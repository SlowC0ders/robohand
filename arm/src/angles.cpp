#include "ros/ros.h"
#include "arm/angles.h" // output message
#include "arm/converter.h" // input message
#define PI 3.14159265 

arm::converter obj;

void chatterCallback(const arm::converter::ConstPtr& msg)
{
  obj.object = msg->object;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "angles"); // initialise node

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<arm::angles>("ang_chatter", 1000); // initialise topic for fourth step programm
  ros::Subscriber sub = n.subscribe("conv_chatter", 1000, chatterCallback); // subscribe on convertor chatter

  ros::Rate loop_rate(10); // establish 10hz loop rate

  //===========================================================================================================
  double length;
    struct vector {
        double x, y, len;
    };
    struct angs { // выходные данные
        double a, b, c, fi;
    };
    struct hand { //параметры манипулятора
        double height, l1, l2, l3, quality = 1;
    };
    struct limbs { 
        vector vec;
        double x, y;
        double ArgMin,ArgMax;
    };

    limbs limb1;
    limbs limb3;
    limbs limb2;
    angs angs;

    hand hand;
    hand.height = 30;
    hand.l1 = 300;
    hand.l2 = 300;
    hand.l3 = 300;
  //===========================================================================================================

  while (ros::ok()) // cycle for sending messages
  {
    arm::angles msg; // create message
  
  //===========================================================================================================
    length = sqrt(pow(obj.object.x, 2) + pow(obj.object.y, 2)); //расстояние от манипулятора до объекта

    for (int i = 0; i < 90; i++) { 
        for (int j = 0; j < 180; j++) {

            limb1.x = (cos(i * PI / 180) * hand.l1);
            limb1.y = (sin(i * PI / 180) * hand.l1 + hand.height);
            limb3.x = (cos(j * PI / 180) * hand.l3 + length);
            limb3.y = (sin(j * PI / 180) * hand.l3);

            limb2.vec.x = limb3.x - limb1.x;
            limb2.vec.y = limb3.y - limb1.y;
            limb2.vec.len = sqrt(pow(limb2.vec.x, 2) + pow(limb2.vec.y, 2));

            if (fabs(limb2.vec.len - hand.l3) < 10) {

                limb1.vec.x = limb1.x;
                limb1.vec.y = limb1.y - hand.height;
                limb1.vec.len = sqrt(pow(limb1.vec.x, 2) + pow(limb1.vec.y, 2));

                limb3.vec.x = length - limb3.x;
                limb3.vec.y = -limb3.y;
                limb3.vec.len = sqrt(pow(limb3.vec.x, 2) + pow(limb3.vec.y, 2));

                angs.a = i;
                angs.b = acos((limb1.vec.x * limb2.vec.x + limb1.vec.y * limb2.vec.y) / limb1.vec.len * limb2.vec.len);
                angs.c = acos((limb2.vec.x * limb3.vec.x + limb2.vec.y * limb3.vec.y) / limb2.vec.len * limb3.vec.len);
            }
        }
    }

    angs.fi = atan(obj.object.y / obj.object.x);

    msg.shoulder = angs.a;
    msg.elbow = angs.b;
    msg.wrist = angs.c;
    msg.rotation = angs.fi;
  //===========================================================================================================

    chatter_pub.publish(msg); // send message

    ros::spinOnce();

    loop_rate.sleep(); // time balancer
  }

  ros::spin();

  return 0;
}