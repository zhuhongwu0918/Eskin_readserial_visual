#include "ros/ros.h"
#include "visualization_msgs/Marker.h"
 
class MarkerPublisher{
public:
    MarkerPublisher(ros::NodeHandle& nh){
        pub_marker_ = nh.advertise<visualization_msgs::Marker>("visualization_marker", 10);//initialize marker publisher
        set_marker_fixed_property();
    };
    void Publish(){
        while (pub_marker_.getNumSubscribers() < 1) {
            sleep(1);
        }
        marker_.header.stamp = ros::Time();
        pub_marker_.publish(marker_);
    };
 
    void set_marker_fixed_property(){
        /*decide from which view we can see the marker*/
        marker_.header.frame_id = "livox_frame";
        marker_.ns = "my_namespace";
        marker_.id = 0;
        //set marker type
        marker_.type = visualization_msgs::Marker::CUBE;
 
        //set marker position
        marker_.pose.position.x = 0;
        marker_.pose.position.y = 0;
        marker_.pose.position.z = 0;
 
        //set marker scale
        marker_.scale.x = 2.0; //m
        marker_.scale.y = 2.0;
        marker_.scale.z = 2.0;
 
        //decide the color of the marker
        marker_.color.a = 1.0; // Don't forget to set the alpha!
        marker_.color.r = 0.0;
        marker_.color.g = 1.0;
        marker_.color.b = 0.0;
 
        //set marker action
        marker_.action = visualization_msgs::Marker::ADD;
        marker_.lifetime = ros::Duration(); //(sec,nsec),0 forever
    };
 
private:
    ros::Publisher  pub_marker_;
    visualization_msgs::Marker marker_;
};
 
int main(int argc, char **argv){
    ros::init(argc, argv, "marker_worker");
    ros::NodeHandle nh;
    MarkerPublisher mp(nh);
    //ros::Rate rate(50);
    //while (ros::ok()) {
    mp.Publish();
    //    rate.sleep();
    //}
    ros::spin();
    return 0;
}