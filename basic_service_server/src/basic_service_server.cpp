#include <ros/ros.h>
#include "tutorial_srvs/TutorialSrv.h"

bool TutorialCommandServiceCallback(tutorial_srvs::TutorialSrv::Request &req,
                                    tutorial_srvs::TutorialSrv::Response &res)
{
  ROS_INFO_STREAM("Receive:" << req.command);

  if(req.command == "forward")
  {
      res.message = "Receive forward";
      res.result = "true";
  }
  else if(req.command == "backward")
  {
      res.message = "Receive backward";
      res.result = "true";
  }
  else
  {
    res.message = "Receive failed";
    res.result = "false";
  }

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_service_server_node");
  ros::NodeHandle n;

  ROS_INFO("basic_service_server_node Open");

  ros::ServiceServer service_server;
  service_server = n.advertiseService("tutorial_command", TutorialCommandServiceCallback);

  ros::Rate loop_rate(1);

  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }

  ROS_INFO("basic_service_server_node Close");

  return 0;

}


// #include <ros/ros.h> 
// #include <tutorial_srvs/TutorialSrv.h>  //add service node 

// bool TutorialServiceCallback(tutorial_srvs::TutorialSrv::Request & req,
//                             tutorial_srvs::TutorialSrv::Response & res)
// {
//     ROS_INFO("Received command: %s", req.command.c_str());
//     if(req.command == "forword"){
//         res.message = "Receive success";
//         res.result = true;
//     }else{
//         res.message = "Receive Fail";
//         res.result = false;
//     }

//     return true;
// }


// int main(int argc, char **argv)
// {
//     ros::init(argc, argv, "basic_service_server_node"); 
//     ros::NodeHandle nh; 

//     ros::ServiceServer service_server;
//     service_server = nh.advertiseService("tutorial_service",TutorialServiceCallback);
    

//     ros::Rate loop_rate(60); 

//     ROS_INFO("basic_service_server_node");
//     while (ros::ok())
//     {
//         ros::spinOnce(); 
//         loop_rate.sleep();
//     }

//     return 0; 
// }
