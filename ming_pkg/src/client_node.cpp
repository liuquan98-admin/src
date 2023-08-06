#include <ros/ros.h>
#include <sstream>
#include <ming_pkg/mysrc.h>
using namespace std;
int main(int argc, char  *argv[])
{
   ros::init(argc,argv,"client_node"); //client_node節點
   ros::NodeHandle ns;

   ros::Rate loop_rate(10);
   ros::ServiceClient client= ns.serviceClient<ming_pkg::mysrc>("service_node");
    while(ros::ok()){
           ming_pkg::mysrc srv;
     if(client.call(srv)){
        
        ROS_INFO("Service responce is:%s",srv.response.name.c_str());
        ROS_INFO("================================================");
     }else{
      ROS_ERROR("RESPONCE ERROR");
        return 1;
     }
        
     
       ros::spinOnce();
       loop_rate.sleep();
    }
    
    return 0;
}
