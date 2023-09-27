//serial_port.cpp
#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>
#include  "../include/serial_port/decode.h"

int getSignBit(int byte) {  

    return (byte & 0x8000) >> 15;  

}  

int clearSignBit(int byte) {  

    return byte & ~0x8000;  

} 

int mergeBit(int byte1, int byte2) {  

    return (byte1 << 8) | byte2;  

} 


int decode(int byte1, int byte2)
{
    int raw1 = byte1;
    int raw2 = byte2;
   int result = mergeBit(raw1,raw2); 
    // std::cout<< "mergeBit: "<<result << std::endl; 
    //判断标志位
    int sign = getSignBit(result);  
    if (sign == 0) {  

        // std::cout << "The byte is positive or zero." << std::endl;  
        // std::cout<< "clearBit: "<<result << std::endl; 

    } else {  

        // std::cout << "The byte is negative." << std::endl;  
        result = clearSignBit(result);
        // std::cout<< "clearBit: "<<result << std::endl; 
        result = -result;

    }  


return result;
}




// int main(int argc, char** argv)
// {
//     ros::init(argc, argv, "decode");
//     //创建句柄（虽然后面没用到这个句柄，但如果不创建，运行时进程会出错）
//     ros::NodeHandle n;
//     // uint8_t raw[] = {0x12, 0xa2} ;
//     uint8_t raw[] = {0xa2, 0x12} ;

//     int result = mergeBit(raw[0],raw[1]); 
//     std::cout<< "mergeBit: "<<result << std::endl; 
//     //判断标志位
//     int sign = getSignBit(result);  
//     if (sign == 0) {  

//         std::cout << "The byte is positive or zero." << std::endl;  
//         std::cout<< "clearBit: "<<result << std::endl; 

//     } else {  

//         std::cout << "The byte is negative." << std::endl;  
//         result = clearSignBit(result);
//         std::cout<< "clearBit: "<<result << std::endl; 

//     }  




//     int buffer[] = {0, 0};

//     buffer[0] = raw[0];
//     buffer[1] = raw[1];
//     // int16_t result = mergeBit(raw[0],raw[2]); 
//     int16_t result = (raw[0] << 8) | raw[2]; 
//     // size_t len = sizeof(buffer)/sizeof(buffer[0]);
//     int len = 2;

//     int sign = getSignBit(raw[1]);  

//     // std::cout<< sign<<std::endl;
//     if (sign == 0) {  

//         std::cout << "The byte is positive or zero." << std::endl;  

//     } else {  

//         std::cout << "The byte is negative." << std::endl;  

//     }  

//     // std::cout<< "decode test!"<<std::hex<<buffer[1]<< std::endl; 
//     std::cout<< "decode test!" << std::endl; 

    
//     for (size_t i = 0; i < len; i++) {
//         std::cout << buffer[i] << ' ';
//     }
//     std::cout << std::endl;
//     std::cout<< "result: "<<result << std::endl; 
//     // int input[] = { 1, 2, 3, 4, 5 };
//     // size_t len = sizeof(input)/sizeof(input[0]);

//     // //循环遍历数组元素


//     return 0;
// }