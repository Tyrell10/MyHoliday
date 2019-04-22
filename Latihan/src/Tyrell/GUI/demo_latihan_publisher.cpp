#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "Tyrell/demo_msg.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)

{
  ros::init(argc, argv,"demo_msg_publisher");
  ros::NodeHandle node_obj;
  ros::Publisher number_publisher = node_obj.advertise<Tyrell::demo_msg>("/demo_msg_topic",10);


  while (ros::ok())
  {
    Tyrell::demo_msg msg;

    std::stringstream ss;
    ss << "halo";
    msg.greeting = ss.str();

    ROS_INFO("%s",msg.greeting.c_str());

    number_publisher.publish(msg);
    ros::spinOnce();
  }

  return 0;
}

