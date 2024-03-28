#include <ros/ros.h> // ROS 라이브러리를 사용하기 위한 헤더 파일

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_node"); // ROS 노드를 초기화하고 노드 이름을 "basic_node"로 설정
  ros::NodeHandle n; // ROS 노드 핸들러 생성

  ros::Rate loop_rate(60); // 주기를 60Hz로 설정하는 Rate 객체 생성 60roop/1sec

  while (ros::ok()) // ROS가 정상적으로 실행 중인 동안 반복
  {
    ROS_INFO("Hello world!"); // "Hello world!" 메시지를 출력
    ros::spinOnce(); // 노드가 수신하는 메시지를 처리하기 위해 ROS에게 제어를 양보
    loop_rate.sleep(); // 주기를 유지하기 위해 대기
  }

  return 0; // 프로그램 종료
}
