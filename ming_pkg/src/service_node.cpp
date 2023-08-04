#include <ros/ros.h>
#include <sstream>
#include <ming_pkg/mysrc.h>
bool service_callback(ming_pkg::mysrc::Request &req,
                      ming_pkg::mysrc::Response &res)
{
  std::stringstream ss;
  ROS_INFO("From client get: [%d],[%d]",req.num_a,req.num_b);
  int sum=req.num_a+req.num_b;
  ss<<"Sum is "<<sum;
  res.name=ss.str();
  return true;
}

int main(int argc, char  *argv[])

{
    ros::init(argc,argv,"service_node");
    ros::NodeHandle ns;
    ros::ServiceServer service=ns.advertiseService("service_sum",service_callback);
    ROS_INFO("ready to Service data from client........");
    ros::spin();
    return 0;
}
