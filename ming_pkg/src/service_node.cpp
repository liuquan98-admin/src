#include <ros/ros.h>
#include <sstream>
#include <ming_pkg/mysrc.h>
 using namespace std;
 
//收到請求後執行回調函數
bool service_callback(ming_pkg::mysrc::Request &req,
                      ming_pkg::mysrc::Response &res)
{
  std::stringstream ss;
  ss<<"Received Here";
  res.name=ss.str();
  ROS_INFO("Form Client[%s],form Service [%s]",req.num_a.c_str(),res.name.c_str());
  return true;
}

int main(int argc, char  *argv[])

{
    ros::init(argc,argv,"service_node");//service_node節點
    ros::NodeHandle ns;
    
    ros::ServiceServer service=ns.advertiseService("service_node",service_callback);
    
    ROS_INFO("ready to Service data from client........");
    ros::spin();
    return 0;
}