//myprotocol.cpp
#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>
// #include  "../include/serial_port/decode.h"
#include  "../include/serial_port/myprotocol.h"



int main(int argc, char** argv)
{
    ros::init(argc, argv, "serial_port");
    //创建句柄（虽然后面没用到这个句柄，但如果不创建，运行时进程会出错）
    ros::NodeHandle n;
    myProtocol mpl;

    //创建一个serial类
    serial::Serial sp;
    //创建timeout
    serial::Timeout to = serial::Timeout::simpleTimeout(100);
    //设置要打开的串口名称
    sp.setPort("/dev/ttyUSB0");
    //设置串口通信的波特率
    sp.setBaudrate(115200);
    //串口设置timeout
    sp.setTimeout(to);
 
    try
    {
        //打开串口
        sp.open();
    }
    catch(serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port.");
        return -1;
    }
    
    //判断串口是否打开成功
    if(sp.isOpen())
    {
        ROS_INFO_STREAM("/dev/ttyUSB0 is opened.");
    }
    else
    {
        return -1;
    }
    
    ros::Rate loop_rate(500);
    while(ros::ok())
    {
        //获取缓冲区内的字节数
        size_t n = sp.available();
        if(n!=0)
        {
            uint8_t buffer[1024];
            //读出数据
            n = sp.read(buffer, n);
            int k=0;

            for(int i=0; i<n; i++)
            {
                //16进制的方式打印到屏幕
                std::cout << std::hex << (buffer[i] & 0xff) << " ";

                // if(buffer[i] == 0xa5)
                // {
                //     int raw[k] = buffer[i];
                //     k++;
                // }
            }
            mpl.decoder(buffer);
            std::cout <<"******buffer end"<< std::endl;
            //把数据发送回去
            // sp.write(buffer, n);
            // slavepl.decode(buffer, n);
            // std::cout <<"mysum: " << mysum( 2, 5 ) <<std::endl;


        // if(buffer[0] == 0xa5 && buffer[1] == 0x62 && buffer[1] == 0x00)
        // {
        //    std::cout<< "Right frame data"<< std::endl;
        //     for (int k=3; k<n; k=k+2)
        //     {
        //     int res = decode(buffer[k],buffer[k+1]);
        //    std::cout <<"ID: " << std::dec <<(int)(k/2)<<", "<<"data:"<< res<<std::endl;
        //     }
        // }

        }


        loop_rate.sleep();
    }
    
    //关闭串口
    sp.close();
 
    return 0;
}
