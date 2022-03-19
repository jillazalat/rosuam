import rospy

# Constants

ZONE_A_HIGH = (None, None, 1)
ZONE_B_HIGH = (None, None, None)
ZONE_A_LOW = (None, None, None)

TARGET_LOC_TOPIC = "/rosuam/target_loc"
CONFIRMATION_TOPIC = "/rosuam/confirm"


class MissionPlanner:
    
    def __init__(self):
        #self.confirmation_sub = rospy.Subscriber('/rosuam/confirmation', int, self.callback)
        self.target_pub = rospy.Publisher(TARGET_LOC_TOPIC, (int, int, int))
        
        # Publish target coordinates for flying upward
        self.target_pub.publish(TARGET_LOC_TOPIC, ZONE_A_HIGH)
        # Wait for confirmation
        rospy.wait_for_message(CONFIRMATION_TOPIC)
        
        # Publish target coordinates for going to zone B
        self.target_pub.publish(TARGET_LOC_TOPIC, ZONE_B_HIGH)
        # Wait for confirmation
        rospy.wait_for_message(CONFIRMATION_TOPIC)
        
        # Use camera for moving to payload
        
        
        self.target_pub.publish(TARGET_LOC_TOPIC, ZONE_A_HIGH)
        rospy.wait_for_message(CONFIRMATION_TOPIC)
        
        self.target_pub.publish(TARGET_LOC_TOPIC, ZONE_A_LOW)
        rospy.wait_for_message(CONFIRMATION_TOPIC)
        
    #def callback(self):
    #    self.
    
    
    def main(args):
        
        planner = MissionPlanner()
        
        # Start other nodes
        