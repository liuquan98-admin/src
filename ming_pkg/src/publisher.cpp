#include <ros/ros.h>
#include <ming_pkg/sttay.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    //1創建節點
    ros::init(argc,argv,"talker_person");

    //2.创建 ROS 句柄
    ros::NodeHandle nh;
    //3.创建发布者对象
    ros::Publisher pub = nh.advertise<ming_pkg::sttay>("/count",10);
    
    ros::Rate r(1);
    
    int number_conunt=0;
   
=
    
    while (ros::ok())
    {
        ming_pkg::sttay p;
        p.name="robot";
        p.deivce_id=number_conunt%5;
        p.percent=rand()/double(RAND_MAX);
        pub.publish(p);
        
        ros::spinOnce();
        r.sleep();
        number_conunt++;
    }
    
    return 0;
}
