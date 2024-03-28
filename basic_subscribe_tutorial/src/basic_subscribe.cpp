#include <ros/ros.h> // ROS 라이브러리를 사용하기 위한 헤더 파일
#include <geometry_msgs/Twist.h> // geometry_msgs 패키지의 Twist 메시지 타입을 사용하기 위한 헤더 파일

// cmd_vel 토픽으로부터 Twist 메시지를 받아들이는 콜백 함수 정의
void CmdVelCallback(const geometry_msgs::Twist::ConstPtr& cmd_vel)
{
  ROS_INFO("subscribe cmd_vel : linear.x = %.3f , angular.z = %.3f", cmd_vel->linear.x, cmd_vel->angular.z);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_subscribe_node"); // ROS 노드를 초기화하고 노드 이름을 "basic_subscribe_node"로 설정
  ros::NodeHandle n; // ROS 노드 핸들러 생성

  ROS_INFO("basic_subscribe_node Open"); // 노드 시작 메시지 출력

  ros::Subscriber subscriber_cmd_vel; // cmd_vel 토픽을 구독하는 Subscriber 생성

  // cmd_vel 토픽을 구독하고, 콜백 함수를 호출하여 메시지를 처리하도록 설정
  subscriber_cmd_vel = n.subscribe("cmd_vel", 1000, CmdVelCallback);

  ros::Rate loop_rate(60); // 주기를 60Hz로 설정하는 Rate 객체 생성

  while (ros::ok()) // ROS가 정상적으로 실행 중인 동안 반복
  {
    ros::spinOnce(); // 노드가 수신하는 메시지를 처리하기 위해 ROS에게 제어를 양보
    loop_rate.sleep(); // 주기를 유지하기 위해 대기
  }
  ROS_INFO("basic_subscribe_node Close"); // 노드 종료 메시지 출력

  return 0; // 프로그램 종료
}


