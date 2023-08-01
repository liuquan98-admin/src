#include <ros/ros.h>
#include <ming_pkg/sttay.h>
#include <stdio.h>

void number_call(const ming_pkg::sttay::ConstPtr& msg){
 ROS_INFO("name is [%s]",msg->name);
 ROS_INFO("deivce is [%d]",msg->deivce_id);
 ROS_INFO("percent is [%f]",msg->percent);


}

int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"subsrc_node");
    ros::NodeHandle ns;
    ns.subscribe<ming_pkg::sttay>("/count",10,number_call);
    ros::spin();
    return 0;
}
