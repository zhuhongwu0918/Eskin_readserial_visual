#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>

int getSignBit(int byte);
int clearSignBit(int byte);
int mergeBit(int byte1, int byte2) ;
int datadecode(int byte1,int byte2);
