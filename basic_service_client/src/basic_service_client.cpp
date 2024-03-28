#include <ros/ros.h>
#include <tutorial_srvs/TutorialSrv.h>

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "basic_service_client_node");

  ros::NodeHandle nh;

  ros::ServiceClient service_client;
  service_client = nh.serviceClient<tutorial_srvs::TutorialSrv>("tutorial_command");

  tutorial_srvs::TutorialSrv tutorial_command;
  tutorial_command.request.command = "forward";

  service_client.call(tutorial_command);

  ROS_INFO_STREAM("Service call command: " << tutorial_command.request.command);
  ROS_INFO_STREAM("Service Response result: " << tutorial_command.response.result);
  ROS_INFO_STREAM("Service Response message: " << tutorial_command.response.message);

//   ROS_INFO("Service call command: %s",tutorial_command.request.command.c_str());
//   ROS_INFO("Service Response result: %s", tutorial_command.response.result.c_str());
//   ROS_INFO("Service Response message: %s", tutorial_command.response.message.c_str());

  return 0;
}

