#!/usr/bin/env python3
# RUN ON PI
import rospy
import time
from adafruit_servokit import ServoKit
import roslib
import sys
from std_msgs.msg import Int32
from sensor_msgs.msg import Image
kit = ServoKit(channels=16)

def gripper_callback(data):
    grip_target_angle = data.data
#    rospy.loginfo("grip angle: "+ str(data.data))
    kit.servo[0].angle=grip_target_angle
def elbow_callback(data):
    elbow_angle = data.data
    rospy.loginfo("elbow angle: " + str(data.data))
    kit.servo[1].angle=elbow_angle
#    time.sleep(0.2)
def approach_callback(data):
    approach_angle = data.data
    kit.servo[2].angle=approach_angle
    
def listener():
    rospy.init_node('arm_client', anonymous=True)
    rospy.Subscriber('gripper_angle', Int32, gripper_callback)
    rospy.Subscriber('tilt_angle', Int32, elbow_callback)
    rospy.Subscriber('approach_angle',Int32,approach_callback)
    kit.servo[0].angle = 0
    kit.servo[1].angle = 35
    kit.servo[2].angle = 130
    rospy.spin()


if __name__ == '__main__':
    listener()


