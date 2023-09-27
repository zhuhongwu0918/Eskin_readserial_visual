#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
#include <eigen3/Eigen/Eigen>





class MarkerPublisher{
public:
    MarkerPublisher(ros::NodeHandle& nh)
    {
        pub_marker_ = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10);//initialize marker publisher
        pub_marker_2 = nh.advertise<visualization_msgs::Marker>("visualization_marker2", 10);//initialize marker publisher
    };
    void Publish(visualization_msgs::Marker &marker_)
    {
        marker_ = marker_;
        // while (pub_marker_.getNumSubscribers() < 1) {
        //     sleep(1);
        // }
        marker_.header.stamp = ros::Time();
        pub_marker_.publish(marker_);
    };

    void Publish2(visualization_msgs::Marker &marker_2)
    {
        // while (pub_marker_2.getNumSubscribers() < 1) {
        //     sleep(1);
        // }
        marker_2 = marker_2;
        marker_2.header.stamp = ros::Time();
        pub_marker_2.publish(marker_2);
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
            marker_.pose.position.z = 0.6;

            marker_.pose.orientation.x = 1;
            marker_.pose.orientation.y = 1;
            marker_.pose.orientation.z = 0;
            marker_.pose.orientation.w = 0.;
            
            marker_.scale.x = 3;
            marker_.scale.y = 0.1;
            marker_.scale.z = 0.1;
            
            marker_.color.r = 1.;
            marker_.color.g = 0.3;
            marker_.color.b = 0.;
            marker_.color.a = 0.8;
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
    ros::Publisher  pub_marker_ , pub_marker_2;
    visualization_msgs::Marker marker_, marker_2;
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
    mp.set_marker_fixed_property(mp.marker_);
    mp.set_marker_fixed_property(mp.marker_2);

      while (ros::ok())
  {


      float x = 0.1 * sin(50*f);
      ROS_INFO("x ,%f", x);
      float y = 0.1 * cos(30*f);

    double roll =0, pitch=0, yaw=- 3.14/2;
    Eigen::Quaterniond q = mp.euler2Quaternion(roll, pitch, yaw);

    ROS_INFO("x,%f", x);
    mp.marker_.pose.orientation.x = q.x();
    mp.marker_.pose.orientation.y = q.y();
    mp.marker_.pose.orientation.z = q.z();
    mp.marker_.pose.orientation.w = q.w();
    ROS_INFO("mp.marker_.pose.orientation.x,%f", mp.marker_.pose.orientation.x);
    ROS_INFO("mp.marker_.pose.orientation.y,%f", mp.marker_.pose.orientation.y);


    roll = 0.1 * sin(50*f);
    ROS_INFO("x ,%f", x);
    pitch = 0.1 * cos(100*f);
    q = mp.euler2Quaternion(roll, pitch, yaw);

    mp.marker_2.pose.position.x = 0.5 + 0.8;
    // mp.marker_2.pose.orientation.y = x;
    mp.marker_2.pose.orientation.x = q.x();
    mp.marker_2.pose.orientation.y = q.y();
    mp.marker_2.pose.orientation.z = q.z();
    mp.marker_2.pose.orientation.w = q.w();
    ROS_INFO("mp.marker_2.pose.orientation.x,%f", mp.marker_2.pose.orientation.x);
    mp.marker_2.pose.orientation.z = y;
    ROS_INFO("mp.marker_2.pose.orientation.y,%f", mp.marker_2.pose.orientation.y);
    
    
    mp.Publish(mp.marker_);
    ROS_INFO("f,%f", f);
    ROS_INFO("mp.Publish()");


    mp.Publish2(mp.marker_2);
    ROS_INFO("mp.Publish2()");





    loop_rate.sleep();
    f += 0.04;
    ROS_INFO("f,%f", f);
  }


    return 0;
}