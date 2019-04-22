#include "ros/ros.h"
#include "Tyrell/demo_msg.h"
#include <iostream>
#include <sstream>

void number_callback(const Tyrell::demo_msg::ConstPtr& msg)
{
  ROS_INFO("Recieved  greeting [%s]",msg->greeting.c_str());
}

int main(int argc, char **argv)

{
  ros::init(argc, argv,"demo_msg_subscriber");
  //Created a nodehandle object
  ros::NodeHandle node_obj;
  //Create a publisher object
  ros::spin();
  return 0;
}

