#!/usr/bin/env python
from __future__ import print_function

import roslib
import sys
import rospy
import cv2
from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import CompressedImage
import numpy as np


class image_converter:

    def __init__(self):
        self.image_pub = rospy.Publisher("image_topic_2", Image)

        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber(
            "/raspicam_node/image/compressed", CompressedImage, self.callback)
        print("<< Subscribed to topic /raspicam_node/image")

    def callback(self, data):
        try:
            cv_image = self.bridge.compressed_imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            print(e)

           # Image manipulation stuff
           # -------------------------------------------
        # (rows,cols,channels) = cv_image.shape
        # if cols > 60 and rows > 60 :
        # cv2.circle(cv_image, (50,50), 10, 255)

        ## Instructables Step 4 - convert BGR to HSV ##
        # color vals found from ms paint eyedropper tool
        blue = 210
        green = 159
        red = 102
        color = np.uint8([[[blue, green, red]]])
        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
        frame = cv_image
        hue = hsv[0][0][0]
        colorLower = (94, 100, 100)
        colorUpper = (114, 255, 255)

        # --------------------------------------------
        mask_img = self.get_masked_image(cv_image)
        contours, hierarchy = cv2.findContours(mask_img, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        center = None
        if len(contours) > 0:
            c = max(contours, key=cv2.contourArea)
            ((x,y), radius) = cv2.minEnclosingCircle(c)
            M= cv2.moments(c)
            center=(int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
            if radius > 10:
            # draw the circle and centroid on the frame,
            # then update the list of tracked points
                cv2.circle(cv_image, (int(x), int(y)), int(radius), (0, 255, 255), 2)
                cv2.circle(cv_image, center, 5, (0, 0, 255), -1)
        #print(x,y)
	# Show video stream of blue box with circle around it
        imS = cv2.resize(cv_image, (250, 250))  		     
        cv2.imshow("blue box live feed", imS)
        #cv2.imshow("Black Background Tracking", black_img)
        cv2.waitKey(3)
        # Show video stream of just the mask
        imS = cv2.resize(mask_img, (250, 250))
        cv2.imshow("mask stream", imS)
        cv2.waitKey(3)
        try:
            self.image_pub.publish(self.bridge.cv2_to_imgmsg(cv_image, "bgr8"))
        except CvBridgeError as e:
            print(e)
        

    def get_masked_image(self, cv_image):
        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
        colorLower = (94, 100, 100)
        colorUpper = (114, 255, 255)
        mask = cv2.inRange(hsv, colorLower, colorUpper)
        return mask


    
def main(args):
    ic = image_converter()
    rospy.init_node('image_converter', anonymous=True)
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down")
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main(sys.argv)
