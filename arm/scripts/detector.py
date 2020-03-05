#!/usr/bin/env python

import rospy
from arm.msg import detector # import our custom message

def talker():
    pub = rospy.Publisher('det_chatter', detector, queue_size=10) # create publisher
    rospy.init_node('detector', anonymous=True) # node initialisation
    rate = rospy.Rate(1) # 10Hz. Determine the frequency
    message = detector() # build message
    while not rospy.is_shutdown(): # while true (except ctrl+c, kill and duplication)
        message.object.x = 10;
	rospy.loginfo(message) # print
        pub.publish(message) # send to converter
        rate.sleep() # time balancer

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
