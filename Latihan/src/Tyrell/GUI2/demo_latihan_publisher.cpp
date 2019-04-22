#include "ros/ros.h"
#include "std_msgs/String.h"
#include "Tyrell/latihan_msg.h"
#include <iostream>
#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv);
    ros::NodeHandle nh;

    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);


        std_msgs::String msg;
        msg.data = input_pesan;

        chatter_pub.publish(msg);

        ros::spinOnce();


    return 0;
}
