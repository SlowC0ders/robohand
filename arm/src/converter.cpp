#include "ros/ros.h"
#include "arm/detector.h" // input message
#include "arm/converter.h" // output message

void chatterCallback(const arm::detector::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->object.x); // print in console
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "converter"); // initialise node

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<arm::converter>("conv_chatter", 1000); // initialise topic for third step programm (angles_converter.cpp)
  ros::Subscriber sub = n.subscribe("det_chatter", 1000, chatterCallback); // subscribe on detector chatter

  ros::Rate loop_rate(10); // establish 10hz loop rate

  while (ros::ok()) // cycle for sending messages
  {
    arm::converter msg; // create message

    msg.object.x = 10;

    ROS_INFO("%d", msg.object.x); // print message

    chatter_pub.publish(msg); // send message

    ros::spinOnce();

    loop_rate.sleep(); // time balancer
  }

  ros::spin();

  return 0;
}
