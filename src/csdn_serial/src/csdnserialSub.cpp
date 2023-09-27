#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>//包含流的操作的C++头文件
std::string myStr="init";//定义全局变量并进行初始化
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  std::stringstream ss;
  ss << msg->data.c_str();
  ss >> ::myStr;//通过流操作进行传参。此处不能用=，报错显示=没有被重装载。该全局变量就可以在main()中使用了。
  std::cout <<"copy_data is: " << myStr <<"\n";
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("read", 1000, chatterCallback);
  ros::spin();
  return 0;
}