#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
#include <eigen3/Eigen/Eigen>





class MarkerPublisher{
public:
    MarkerPublisher(ros::NodeHandle& nh)
    {
        pub_marker_1 = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10);//initialize marker publisher
        pub_marker_2 = nh.advertise<visualization_msgs::Marker>("visualization_marker2", 10);//initialize marker publisher
        pub_marker_3 = nh.advertise<visualization_msgs::Marker>("visualization_marker3", 10);//initialize marker publisher
        pub_marker_4 = nh.advertise<visualization_msgs::Marker>("visualization_marker4", 10);//initialize marker publisher

        pub_marker_5 = nh.advertise<visualization_msgs::Marker>("visualization_marker5", 10);//initialize marker publisher
        pub_marker_6 = nh.advertise<visualization_msgs::Marker>("visualization_marker6", 10);//initialize marker publisher
        pub_marker_7 = nh.advertise<visualization_msgs::Marker>("visualization_marker7", 10);//initialize marker publisher
        pub_marker_8 = nh.advertise<visualization_msgs::Marker>("visualization_marker8", 10);//initialize marker publisher

        pub_marker_9 = nh.advertise<visualization_msgs::Marker>("visualization_marker9", 10);//initialize marker publisher
        pub_marker_10 = nh.advertise<visualization_msgs::Marker>("visualization_marker10", 10);//initialize marker publisher
        pub_marker_11 = nh.advertise<visualization_msgs::Marker>("visualization_marker11", 10);//initialize marker publisher
        pub_marker_12 = nh.advertise<visualization_msgs::Marker>("visualization_marker12", 10);//initialize marker publisher

        pub_marker_13 = nh.advertise<visualization_msgs::Marker>("visualization_marker13", 10);//initialize marker publisher
        pub_marker_14 = nh.advertise<visualization_msgs::Marker>("visualization_marker14", 10);//initialize marker publisher
        pub_marker_15 = nh.advertise<visualization_msgs::Marker>("visualization_marker15", 10);//initialize marker publisher
        pub_marker_16 = nh.advertise<visualization_msgs::Marker>("visualization_marker16", 10);//initialize marker publisher
    };
    void Publish(visualization_msgs::Marker &marker_ , ros::Publisher &pub_marker)
    {
        marker_ = marker_;
        // while (pub_marker_.getNumSubscribers() < 1) {
        //     sleep(1);
        // }
        marker_.header.stamp = ros::Time();
        pub_marker.publish(marker_);
    };
 
    void set_marker_fixed_property(visualization_msgs::Marker &marker_)
    {
           marker_.header.frame_id = "/base_link";
            marker_.ns = "shapes";
            marker_.id = 0;
            
            marker_.type = visualization_msgs::Marker::ARROW;
            
            marker_.action = visualization_msgs::Marker::ADD;
            marker_.lifetime = ros::Duration(); //(sec,nsec),0 forever
            marker_.pose.position.x = 0.5;
            marker_.pose.position.y = 1.1;
            marker_.pose.position.z = 0.4;

            marker_.pose.orientation.x = 1;
            marker_.pose.orientation.y = 1;
            marker_.pose.orientation.z = 0;
            marker_.pose.orientation.w = 0.;
            
            marker_.scale.x = 2;
            marker_.scale.y = 0.05;
            marker_.scale.z = 0.05;
            
            marker_.color.r = 1.;
            marker_.color.g = 0.3;
            marker_.color.b = 0.;
            marker_.color.a = 0.9;
    };
     Eigen::Quaterniond euler2Quaternion(const double roll, const double pitch, const double yaw)  
    {  
        Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitZ());  
        Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitY());  
        Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitX());  
    
        Eigen::Quaterniond q = rollAngle * yawAngle * pitchAngle;  
        std::cout << "Euler2Quaternion result is:" <<std::endl;  
        std::cout << "x = " << q.x() <<std::endl;  
        std::cout << "y = " << q.y() <<std::endl;  
        std::cout << "z = " << q.z() <<std::endl;  
        std::cout << "w = " << q.w() <<std::endl<<std::endl;  
        return q;  
    }   


public:
    ros::Publisher  pub_marker_1 , pub_marker_2,pub_marker_3 , pub_marker_4;
    ros::Publisher  pub_marker_5 , pub_marker_6,pub_marker_7, pub_marker_8;
    ros::Publisher  pub_marker_9 , pub_marker_10,pub_marker_11, pub_marker_12;
    ros::Publisher  pub_marker_13 , pub_marker_14,pub_marker_15 , pub_marker_16;

    visualization_msgs::Marker marker_1, marker_2, marker_3, marker_4;
    visualization_msgs::Marker marker_5, marker_6, marker_7, marker_8;
    visualization_msgs::Marker marker_9, marker_10, marker_11, marker_12;
    visualization_msgs::Marker marker_13, marker_14, marker_15, marker_16;
};
 

int main(int argc, char **argv)
{
// ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Info);
// ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Warn);

    ros::init(argc, argv, "marker_worker");
    ros::NodeHandle nh;
    MarkerPublisher mp(nh);

    ros::Rate loop_rate(10);
    float f = 0.0;
    float x = 0.0;
    float y = 0.0;
    mp.set_marker_fixed_property(mp.marker_1);
    mp.set_marker_fixed_property(mp.marker_2);
    mp.set_marker_fixed_property(mp.marker_3);
    mp.set_marker_fixed_property(mp.marker_4);

    mp.set_marker_fixed_property(mp.marker_5);
    mp.set_marker_fixed_property(mp.marker_6);
    mp.set_marker_fixed_property(mp.marker_7);
    mp.set_marker_fixed_property(mp.marker_8);

    mp.set_marker_fixed_property(mp.marker_9);
    mp.set_marker_fixed_property(mp.marker_10);
    mp.set_marker_fixed_property(mp.marker_11);
    mp.set_marker_fixed_property(mp.marker_12);

    mp.set_marker_fixed_property(mp.marker_13);
    mp.set_marker_fixed_property(mp.marker_14);
    mp.set_marker_fixed_property(mp.marker_15);
    mp.set_marker_fixed_property(mp.marker_16);

      while (ros::ok())
  {


      float x = 0.1 * sin(50*f);
      ROS_INFO("x ,%f", x);
      float y = 0.1 * cos(30*f);

    double roll =0, pitch=0, yaw=- 3.14/2;
    Eigen::Quaterniond q = mp.euler2Quaternion(roll, pitch, yaw);

    pitch = 0.05 * sin(50*f);
    ROS_INFO("x ,%f", x);
    yaw = 0.05 * cos(100*f);
    q = mp.euler2Quaternion(roll, pitch, yaw- 3.14/2);


    ROS_INFO("x,%f", x);
    mp.marker_1.pose.position.x = 0.5 + 0.8*0;
    mp.marker_1.pose.position.y = 1.1;
    mp.marker_1.pose.orientation.x = q.x();
    mp.marker_1.pose.orientation.y = q.y();
    mp.marker_1.pose.orientation.z = q.z();
    mp.marker_1.pose.orientation.w = q.w();
    ROS_INFO("mp.marker_.pose.orientation.x,%f", mp.marker_1.pose.orientation.x);
    ROS_INFO("mp.marker_.pose.orientation.y,%f", mp.marker_2.pose.orientation.y);

    mp.marker_2.pose.position.x = 0.5 + 0.8;
    mp.marker_2.pose.position.y = 1.1;
    mp.marker_2.pose.orientation.x = q.x();
    mp.marker_2.pose.orientation.y = q.y();
    mp.marker_2.pose.orientation.z = q.z();
    mp.marker_2.pose.orientation.w = q.w();
    ROS_INFO("mp.marker_2.pose.orientation.x,%f", mp.marker_2.pose.orientation.x);
    ROS_INFO("mp.marker_2.pose.orientation.y,%f", mp.marker_2.pose.orientation.y);
    
    mp.marker_3.pose.position.x = 0.5 + 0.8*2;
    mp.marker_3.pose.position.y = 1.1;
    mp.marker_3.pose.orientation.x = q.x();
    mp.marker_3.pose.orientation.y = q.y();
    mp.marker_3.pose.orientation.z = q.z();
    mp.marker_3.pose.orientation.w = q.w();

    mp.marker_4.pose.position.x = 0.5 + 0.8*3;
    mp.marker_4.pose.position.y = 1.1 ;
    mp.marker_4.pose.orientation.x = q.x();
    mp.marker_4.pose.orientation.y = q.y();
    mp.marker_4.pose.orientation.z = q.z();
    mp.marker_4.pose.orientation.w = q.w();

    mp.marker_5.pose.position.x = 0.5 + 0.8*0;
    mp.marker_5.pose.position.y = 1.1 + 1.1*1;
    mp.marker_5.pose.orientation.x = q.x();
    mp.marker_5.pose.orientation.y = q.y();
    mp.marker_5.pose.orientation.z = q.z();
    mp.marker_5.pose.orientation.w = q.w();

    mp.marker_6.pose.position.x = 0.5 + 0.8*1;
    mp.marker_6.pose.position.y = 1.1 + 1.1*1;
    mp.marker_6.pose.orientation.x = q.x();
    mp.marker_6.pose.orientation.y = q.y();
    mp.marker_6.pose.orientation.z = q.z();
    mp.marker_6.pose.orientation.w = q.w();

    mp.marker_7.pose.position.x = 0.5 + 0.8*2;
    mp.marker_7.pose.position.y = 1.1+ 1.1*1;
    mp.marker_7.pose.orientation.x = q.x();
    mp.marker_7.pose.orientation.y = q.y();
    mp.marker_7.pose.orientation.z = q.z();
    mp.marker_7.pose.orientation.w = q.w();

    mp.marker_8.pose.position.x = 0.5 + 0.8*3;
    mp.marker_8.pose.position.y = 1.1 + 1.1*1;
    mp.marker_8.pose.orientation.x = q.x();
    mp.marker_8.pose.orientation.y = q.y();
    mp.marker_8.pose.orientation.z = q.z();
    mp.marker_8.pose.orientation.w = q.w();

    mp.marker_9.pose.position.x = 0.5 + 0.8*0;
    mp.marker_9.pose.position.y = 1.1 + 1.1*2;
    mp.marker_9.pose.orientation.x = q.x();
    mp.marker_9.pose.orientation.y = q.y();
    mp.marker_9.pose.orientation.z = q.z();
    mp.marker_9.pose.orientation.w = q.w();

    mp.marker_10.pose.position.x = 0.5 + 0.8*1;
    mp.marker_10.pose.position.y = 1.1 + 1.1*2;
    mp.marker_10.pose.orientation.x = q.x();
    mp.marker_10.pose.orientation.y = q.y();
    mp.marker_10.pose.orientation.z = q.z();
    mp.marker_10.pose.orientation.w = q.w();

    mp.marker_11.pose.position.x = 0.5 + 0.8*2;
    mp.marker_11.pose.position.y = 1.1 + 1.1*2;
    mp.marker_11.pose.orientation.x = q.x();
    mp.marker_11.pose.orientation.y = q.y();
    mp.marker_11.pose.orientation.z = q.z();
    mp.marker_11.pose.orientation.w = q.w();

    mp.marker_12.pose.position.x = 0.5 + 0.8*3;
    mp.marker_12.pose.position.y = 1.1 + 1.1*2;
    mp.marker_12.pose.orientation.x = q.x();
    mp.marker_12.pose.orientation.y = q.y();
    mp.marker_12.pose.orientation.z = q.z();
    mp.marker_12.pose.orientation.w = q.w();

    mp.marker_13.pose.position.x = 0.5 + 0.8*0;
    mp.marker_13.pose.position.y = 1.1 + 1.1*3;
    mp.marker_13.pose.orientation.x = q.x();
    mp.marker_13.pose.orientation.y = q.y();
    mp.marker_13.pose.orientation.z = q.z();
    mp.marker_13.pose.orientation.w = q.w();

    mp.marker_14.pose.position.x = 0.5 + 0.8*1;
    mp.marker_14.pose.position.y = 1.1 + 1.1*3;
    mp.marker_14.pose.orientation.x = q.x();
    mp.marker_14.pose.orientation.y = q.y();
    mp.marker_14.pose.orientation.z = q.z();
    mp.marker_14.pose.orientation.w = q.w();

    mp.marker_15.pose.position.x = 0.5 + 0.8*2;
    mp.marker_15.pose.position.y = 1.1 + 1.1*3;
    mp.marker_15.pose.orientation.x = q.x();
    mp.marker_15.pose.orientation.y = q.y();
    mp.marker_15.pose.orientation.z = q.z();
    mp.marker_15.pose.orientation.w = q.w();

    mp.marker_16.pose.position.x = 0.5 + 0.8*3;
    mp.marker_16.pose.position.y = 1.1 + 1.1*3;
    mp.marker_16.pose.orientation.x = q.x();
    mp.marker_16.pose.orientation.y = q.y();
    mp.marker_16.pose.orientation.z = q.z();
    mp.marker_16.pose.orientation.w = q.w();

    mp.Publish(mp.marker_1, mp.pub_marker_1);
    mp.Publish(mp.marker_2, mp.pub_marker_2);
    mp.Publish(mp.marker_3, mp.pub_marker_3);
    mp.Publish(mp.marker_4, mp.pub_marker_4);
    
    mp.Publish(mp.marker_5, mp.pub_marker_5);
    mp.Publish(mp.marker_6, mp.pub_marker_6);
    mp.Publish(mp.marker_7, mp.pub_marker_7);
    mp.Publish(mp.marker_8, mp.pub_marker_8);

    mp.Publish(mp.marker_9, mp.pub_marker_9);
    mp.Publish(mp.marker_10, mp.pub_marker_10);
    mp.Publish(mp.marker_11, mp.pub_marker_11);
    mp.Publish(mp.marker_12, mp.pub_marker_12);

    mp.Publish(mp.marker_13, mp.pub_marker_13);
    mp.Publish(mp.marker_14, mp.pub_marker_14);
    mp.Publish(mp.marker_15, mp.pub_marker_15);
    mp.Publish(mp.marker_16, mp.pub_marker_16);


    loop_rate.sleep();
    f += 0.04;
    ROS_INFO("f,%f", f);
  }


    return 0;
}