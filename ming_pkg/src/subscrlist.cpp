#include <ros/ros.h>
#include <ming_pkg/sttay.h>
#include <stdio.h>

void number_call(const ming_pkg::sttay::ConstPtr& msg){
 ROS_INFO("name is [%s],deivce is[%d],percent is [%f]",msg->name.c_str(),msg->deivce_id,msg->percent);



}
int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"subsrc_node");
    ros::NodeHandle ns;
    ros:: Subscriber number_subscriber=ns.subscribe<ming_pkg::sttay>("/count",10,number_call);
    ros::spin();
  
    return 0;
}
