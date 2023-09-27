#include "ros/ros.h"
#include "visualization_msgs/Marker.h"

void callback1(const ros::TimerEvent&)
{
  ROS_INFO("Callback 1 triggered");
}

void callback2(const ros::TimerEvent&)
{
  ROS_INFO("Callback 2 triggered");
}

int main(int argc, char **argv){
    // ros::init(argc, argv, "marker_worker");
    // ros::NodeHandle nh;




    // ros::Rate rate(10);
    // while (ros::ok()) {

    // ROS_INFO("published!");

    // ros::spinOnce();
    // //loop_rate.sleep();
    // rate.sleep();
    // }
    // // ros::spin();
    // return 0;

     ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  //定时器1每100ms执行一次
  ros::Timer timer1 = n.createTimer(ros::Duration(0.1), callback1);
  
  //定时器2每1秒执行一次
  ros::Timer timer2 = n.createTimer(ros::Duration(1.0), callback2);

  ros::spin();

  return 0;
}