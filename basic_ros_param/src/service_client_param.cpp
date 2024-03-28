#include "ros/ros.h"                          // ROS 라이브러리를 포함합니다.
#include "basic_ros_param/CalculateSrv.h"     // 사용할 서비스 메시지 헤더 파일을 포함합니다.
#include <cstdlib>                            

int main(int argc, char **argv)              // 메인 함수 시작
{
  ros::init(argc, argv, "service_client_param");    // 노드를 초기화합니다.

  if (argc != 3)  // 만약 인자의 수가 3이 아니라면
  {
    ROS_INFO("cmd : rosrun ros_param service_client_param arg0 arg1");  // 사용법을 출력합니다.
    ROS_INFO("arg0: double number, arg1: double number");               // 인자의 설명을 출력합니다.
    return 1;  // 종료코드 1로 프로그램을 종료합니다.
  }

  ros::NodeHandle nh;       // 노드 핸들러를 생성합니다.

  ros::ServiceClient ros_param_client = nh.serviceClient<basic_ros_param::CalculateSrv>("calculate_param_srv");  // 서비스 클라이언트를 설정합니다.

  basic_ros_param::CalculateSrv srv;  // 서비스 메시지를 생성합니다.

  srv.request.a = atoll(argv[1]);  // 서비스 메시지의 요청값 a를 설정합니다.
  srv.request.b = atoll(argv[2]);  // 서비스 메시지의 요청값 b를 설정합니다.

  if (ros_param_client.call(srv))  // 서비스를 호출하고, 성공적으로 호출되었는지 확인합니다.
  {
    ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);  // 서비스 요청값을 출력합니다.
    ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);  // 서비스 응답값을 출력합니다.
  }
  else
  {
    ROS_ERROR("Failed to call service ros_param_srv");  // 서비스 호출에 실패했을 경우 에러 메시지를 출력합니다.
    return 1;  // 종료코드 1로 프로그램을 종료합니다.
  }
  return 0;  // 정상적으로 종료되었음을 나타내며 프로그램을 종료합니다.
}
