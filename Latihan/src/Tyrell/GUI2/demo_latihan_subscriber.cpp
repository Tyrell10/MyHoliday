#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Tyrell/latihan_msg.h"
#include <iostream>
#include <sstream>

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO(msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv);
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

    ros::spin();

    return 0;
}
