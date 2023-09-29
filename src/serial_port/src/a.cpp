#include "ros/ros.h"

#include "std_msgs/String.h"
#include "../include/serial_port/b.h"
#include <sstream>
#include  "../include/serial_port/decode.h"
// int mysum(int x, int y);
/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "a_node");
    uint8_t raw[] = {0x8d, 0x25} ;
    // std::cout << std::dec << raw[0]<<std::endl;

    int result = mergeBit(raw[0],raw[1]); 
    std::cout<< "mergeBit: "<<std::dec <<result << std::endl; 

  result = clearSignBit(result);
  std::cout<< "clearBit: "<<-result << std::endl; 



    // int res = decode(raw[0],raw[1]);
    // std::cout<<"this is decoded:"<<std::dec << res <<std::endl;

    int k=13;
    std::cout <<"13%2: " << k/2<<std::endl;
    // std::cout <<"ID: " << (int)(k/2)<<", "<<"data:"<< res<<std::endl;

  return 0;
}