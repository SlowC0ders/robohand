#include "ros/ros.h"
#include "arm/angles.h" // output message
#include "arm/converter.h" // input message

void chatterCallback(const arm::converter::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->object.x); // print in console
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "angles"); // initialise node

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<arm::angles>("ang_chatter", 1000); // initialise topic for fourth step programm
  ros::Subscriber sub = n.subscribe("conv_chatter", 1000, chatterCallback); // subscribe on convertor chatter

  ros::Rate loop_rate(10); // establish 10hz loop rate

  while (ros::ok()) // cycle for sending messages
  {
    arm::angles msg; // create message

    msg.shoulder = 10;

    ROS_INFO("%d", msg.shoulder); // print message

    chatter_pub.publish(msg); // send message

    ros::spinOnce();

    loop_rate.sleep(); // time balancer
  }

  ros::spin();

  return 0;
}

