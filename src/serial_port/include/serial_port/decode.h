#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>

int getSignBit(int byte);
int clearSignBit(int byte);
int mergeBit(int byte1, int byte2) ;
int decode(int byte1,int byte2);
