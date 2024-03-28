#include <ros/ros.h> // ROS 라이브러리를 사용하기 위한 헤더 파일
#include <geometry_msgs/Twist.h> // geometry_msgs 패키지의 Twist 메시지 타입을 사용하기 위한 헤더 파일

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_publish_node"); // ROS 노드를 초기화하고 노드 이름을 "basic_publish_node"로 설정
  ros::NodeHandle n; // ROS 노드 핸들러 생성

  geometry_msgs::Twist cmd_vel; // geometry_msgs 패키지의 Twist 메시지 타입을 사용하여 cmd_vel 객체 생성
  ros::Publisher publisher_cmd_vel = n.advertise<geometry_msgs::Twist>("cmd_vel", 1000); // cmd_vel 토픽에 Twist 메시지를 발행하는 Publisher 생성

  ros::Rate loop_rate(60); // 주기를 60Hz로 설정하는 Rate 객체 생성

  while (ros::ok()) // ROS가 정상적으로 실행 중인 동안 반복
  {
    cmd_vel.linear.x = 10; // 선속도(x축 방향)를 10으로 설정
    cmd_vel.angular.z = 10; // 각속도(z축 방향)를 10으로 설정
    publisher_cmd_vel.publish(cmd_vel); // cmd_vel 토픽으로 Twist 메시지를 발행

    ros::spinOnce(); // 노드가 수신하는 메시지를 처리하기 위해 ROS에게 제어를 양보
    loop_rate.sleep(); // 주기를 유지하기 위해 대기
  }

  return 0; // 프로그램 종료
}
