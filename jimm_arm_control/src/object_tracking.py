#!/usr/bin/env python
# References:
# ROS cv_bridge sample code
# https://github.com/trunc8/ball-tracking-opencv-and-ros
# https://www.instructables.com/Automatic-Vision-Object-Tracking/
# OpenCV Contour Features Documentation -- also cite OpenCV
# taredevarsh and opencv tutorial on z distance

from __future__ import print_function
import roslib
import sys
import rospy
import cv2
from std_msgs.msg import String, Int32
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import CompressedImage
import numpy as np
import time
import imutils

class image_converter:

    def __init__(self):
        #self.image_pub = rospy.Publisher("image_topic_2", Image)
        self.gripper_pub = rospy.Publisher("/rosuam/gripper_angle", Int32, queue_size=1)
        self.tilt_pub = rospy.Publisher("/rosuam/tilt_angle", Int32, queue_size=1)
        self.approach_pub = rospy.Publisher("/rosuam/approach_angle", Int32, queue_size=1)
        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber(
            "/raspicam_node/image/compressed", CompressedImage, self.callback)
        print("<< Subscribed to topic /raspicam_node/image")
        
        self.OBJECT_CENTERED = False
        self.GRIPPER_GRABBED_OBJECT = False
        self.goToHomeConfiguration()
        rospy.sleep(2)
        self.tryMoveApproach(0)
        self.tryMoveElbow(0)
        
    def getMaskedImage(self, cv_image):
        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
        colorLower = (94, 100, 100)
        colorUpper = (114, 255, 255)
        mask = cv2.inRange(hsv, colorLower, colorUpper)
        return mask
    
    # Functions to set servo angles
    def setApproachAngle(self, angle):
        self.CURRENT_APPROACH_ANGLE = angle
        self.approach_pub.publish(self.CURRENT_APPROACH_ANGLE)
    
    def setElbowAngle(self, angle):
        self.CURRENT_ELBOW_ANGLE = angle
        self.tilt_pub.publish(self.CURRENT_ELBOW_ANGLE)
    
    def openGripper(self):
        GRIPPER_OPEN_ANGLE = 90
        self.gripper_pub.publish(GRIPPER_OPEN_ANGLE)
        #rospy.loginfo("Opening gripper")
    
    def closeGripper(self):
        GRIPPER_CLOSE_ANGLE = 5
        self.gripper_pub.publish(GRIPPER_CLOSE_ANGLE)
        #rospy.loginfo("Closing gripper")
    
    def goToHomeConfiguration(self):
        self.CURRENT_APPROACH_ANGLE = 160
        self.CURRENT_ELBOW_ANGLE = 160
    
    # Functions to TRY to change servo angles if in acceptable ranges
    def tryMoveApproach(self, change):
        MIN_APPROACH_ANGLE = 45
        MAX_APPROACH_ANGLE = 160
        newAngle = self.CURRENT_APPROACH_ANGLE + change
        if newAngle < MIN_APPROACH_ANGLE:
            newAngle = MIN_APPROACH_ANGLE
        elif newAngle > MAX_APPROACH_ANGLE:
            newAngle = MAX_APPROACH_ANGLE
        #rospy.loginfo("Changing approach by: " + str(change) + ".\t\tCurrent angle: " + str(self.CURRENT_APPROACH_ANGLE))
        self.setApproachAngle(newAngle)
    
    def tryMoveElbow(self, change):
        MIN_ELBOW_ANGLE = 30
        MAX_ELBOW_ANGLE = 160
        newAngle = self.CURRENT_ELBOW_ANGLE + change
        if newAngle < MIN_ELBOW_ANGLE:
            newAngle = MIN_ELBOW_ANGLE
        elif newAngle > MAX_ELBOW_ANGLE:
            newAngle = MAX_ELBOW_ANGLE
        #rospy.loginfo("Changing elbow by: " + str(change) + ".\t\tCurrent angle: " + str(self.CURRENT_ELBOW_ANGLE))
        self.setElbowAngle(newAngle)
    
    # -----------------
    
    def callback(self, data):
        try:
            cv_image = self.bridge.compressed_imgmsg_to_cv2(data, "bgr8")
            cv_image = cv2.flip(cv_image, 0)
        except CvBridgeError as e:
            print(e)
        
        def showCameraStream(cv_image):
            imS = cv2.resize(cv_image, (300, 300))  		     
            cv2.imshow("blue box live feed", imS)
            cv2.waitKey(3)
        
        ##### CONSTANTS #####
        OBJECT_RECOGNITION_RADIUS = 10
        OBJECT_WIDTH = 4.5 # cm
        CAMERA_FOCAL_LENGTH = 360 # Raspberry Pi Camera v1.3
        GRIPPER_OPEN_DISTANCE = 50
        GRIPPER_CLOSE_DISTANCE = 15
        TILT_MIN_LIMIT = 75
        TILT_MAX_LIMIT = 180
        CAMERA_Y_CENTER_MAX = 32 # in the TOP of the video feed (image is inverted)
        CAMERA_Y_CENTER_MIN = 28 # in the BOTTOM of the video feed
        APPROACH_HOME_ANGLE = 90
        TILT_HOME_ANGLE = 25
        APPROACH_FARTHEST_DISTANCE_ANGLE = 90
        APPROACH_CLOSEST_DISTANCE_ANGLE = 0
        #################################
        
        if self.GRIPPER_GRABBED_OBJECT:
            cv2.putText(cv_image, "GRABBED", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)

        mask_img = self.getMaskedImage(cv_image)
        contours, hierarchy = cv2.findContours(mask_img, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        
        if len(contours) > 0 and not self.GRIPPER_GRABBED_OBJECT:
            
            c = max(contours, key=cv2.contourArea)
            ((xc,yc), radius) = cv2.minEnclosingCircle(c) # get radius of largest contour
            
            if radius > OBJECT_RECOGNITION_RADIUS: # Object recognized
                
                # 1. Draw rectangle around object and red dot in center 
                rectangle = cv2.minAreaRect(c) # Draw rectangle around object
                x,y,w,h = cv2.boundingRect(c)
                cv2.rectangle(cv_image, (x, y), (x + w, y + h), (0, 255, 0), 2)
                centerx, centery = x + (w // 2), y + (h // 2)
                center = (centerx, centery)
                cv2.circle(cv_image, center, 3, (0, 0, 255), -1) # Draw red dot in the center of the rectangle

                # 2. Check distance to object and display on video feed
                dist = round((OBJECT_WIDTH*CAMERA_FOCAL_LENGTH / rectangle[1][0]) * 0.8, 1)
                object_pose = (x, y, dist)
                area=round(rectangle[1][0] * rectangle[1][1])
                text = str(object_pose) + " A = " + str(area)#'Distance from camera in cm:'+
                cv2.putText(cv_image, text, (10,20), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)
                
                # 3. Center object in camera frame using motion of elbow joint
                deltaY = y - CAMERA_Y_CENTER_MAX
                if deltaY < 0: # adjust 
                    cv2.putText(cv_image, "Raising", (10, 80), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)
                    #self.tryMoveElbow(int(-deltaY / 10))
                    self.tryMoveElbow(1)
                    #self.tryMoveElbow(1)
            
                elif deltaY > 0:
                    cv2.putText(cv_image, "Lowering", (10, 80), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)
                    #self.tryMoveElbow(int(-deltaY / 10))
                    self.tryMoveElbow(-1)
                    #self.tryMoveElbow(-1)
                    
                # 4. Based on distance to object, either grab it or come closer to it using motion of base joint
                
                if dist <= GRIPPER_CLOSE_DISTANCE:
                    cv2.putText(cv_image, "Close gripper", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)
                    self.closeGripper()
                    self.GRIPPER_GRABBED_OBJECT = True
                    self.goToHomeConfiguration()
                    self.tryMoveApproach(0)
                    #for i in range(5):
                    #    self.tryMoveApproach(1)
                elif dist < GRIPPER_OPEN_DISTANCE:
                    cv2.putText(cv_image, "Open gripper", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)
                    self.openGripper()
                    self.tryMoveApproach(-2)
                    #self.tryMoveElbow(2)
            
            elif radius <= OBJECT_RECOGNITION_RADIUS: # other contours detected
                    cv2.putText(cv_image, "Close gripper", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)
                    self.closeGripper()
                    #self.tryMoveApproach(-1)
                    
        elif len(contours) == 0 and not self.GRIPPER_GRABBED_OBJECT: # nothing detected
            cv2.putText(cv_image, "Close gripper", (10, 50), cv2.FONT_HERSHEY_SIMPLEX, .3, (0, 0, 255), 1, cv2.LINE_AA)
            self.closeGripper()
            #self.tryMoveApproach(-1)
        
        rospy.loginfo("Approach: " + str(self.CURRENT_APPROACH_ANGLE) + "\t\tElbow: " + str(self.CURRENT_ELBOW_ANGLE))
        
        showCameraStream(cv_image)
        # time.sleep(0.01)
          
def main(args):
    rospy.init_node('image_converter', anonymous=True)
    
    rate = rospy.Rate(150)
    ic = image_converter()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down")
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main(sys.argv)
