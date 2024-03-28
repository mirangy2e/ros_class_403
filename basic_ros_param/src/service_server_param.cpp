#include "ros/ros.h"                            // ROS 기본 헤더 파일
#include "basic_ros_param/CalculateSrv.h"       // service 라이브러리 헤더 파일

#define PLUS            1   // 덧셈
#define MINUS           2   // 뺄셈
#define MULTIPLICATION  3   // 곱셈
#define DIVISION        4   // 나눗셈

int g_operator = PLUS;  // 연산자 초기값을 덧셈으로 설정

// 서비스 요청이 있을 경우 아래의 과정이 수행됩니다.
// 서비스 요청은 'req'로 선언하고, 서비스 응답은 'res'로 선언됩니다.
bool calculation(basic_ros_param::CalculateSrv::Request &req,
                 basic_ros_param::CalculateSrv::Response &res)
{
  // 파라미터 값에 따라 연산자가 선택되고, 서비스 요청에서 받은 'a'와 'b'를 계산합니다.
  // 결과는 응답 값으로 저장됩니다.
  switch(g_operator)
  {
    case PLUS:
         res.result = req.a + req.b; break;
    case MINUS:
         res.result = req.a - req.b; break;
    case MULTIPLICATION:
         res.result = req.a * req.b; break;
    case DIVISION:
         if(req.b == 0)
         {
           res.result = 0; break;
         }
         else
         {
           res.result = req.a / req.b; break;
         }
    default:
         res.result = req.a + req.b; break;
  }
  // 서비스 요청에 사용된 'a'와 'b'의 값을 그리고 서비스 응답에 해당하는 'result' 값을 표시합니다.
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.result);

  return true;
}



int main(int argc, char **argv)             // 노드 메인 함수
{
  ros::init(argc, argv, "service_server_param");  // 노드 이름을 초기화합니다.
  ros::NodeHandle nh;                            // 노드 핸들을 선언합니다.

  nh.setParam("calculation_method", PLUS);       // 파라미터 설정을 초기화합니다.

  // 'ros_param' 패키지의 'CalculateSrv' 서비스 파일을 사용하여 'calculate_param_srv'라는 이름의
  // 서비스 서버 'service_server_param'을 선언합니다. 서비스가 요청될 때 'calculation' 함수를 실행하도록 설정됩니다.
  ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("calculate_param_srv", calculation);

  ROS_INFO("ready srv server!");   // 서비스 서버가 준비되었음을 표시합니다.

  ros::Rate loop_rate(1);  // 1 Hz

  while (ros::ok())
  {
    nh.getParam("calculation_method", g_operator);  // 파라미터에서 받은 값에 따라 연산자를 선택합니다.
    ros::spinOnce();          // 콜백 함수 처리 루틴
    loop_rate.sleep();        // 루틴 반복을 위한 대기
  }

  return 0;
}
