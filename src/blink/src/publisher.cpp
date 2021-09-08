#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher");
  
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("led", 1000);
  ros::Rate loop_rate(20);

  std_msgs::String msg;
  msg.data="on";
  int count = 0;
  while (ros::ok())
  {
    if(msg.data=="on"){
        msg.data="off";
    }else{
        msg.data="on";
    }    
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }


  return 0;
}

