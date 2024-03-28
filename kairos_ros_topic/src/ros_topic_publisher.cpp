#include "ros/ros.h"                            // ROS 기본 헤더 파일
#include "kairos_ros_topic/kairosmsg.h"    // MsgTutorial 메시지 파일 헤더. 이 헤더 파일은 패키지를 빌드할 때 자동으로 생성됩니다.

int main(int argc, char **argv)                 // 노드 메인 함수
{
  ros::init(argc, argv, "kairos_topic_publisher");     // 노드 이름 초기화
  ros::NodeHandle nh;                           // ROS 시스템과 통신하기 위한 노드 핸들 선언


  ros::Publisher ros_topic_pub = nh.advertise<kairos_ros_topic::kairosmsg>("kairos_topic_msg", 100);

  // 루프 주기 설정. '1'은 1 Hz를 의미하며, 메인 루프가 1초 간격으로 반복됩니다.
  ros::Rate loop_rate(1);

  kairos_ros_topic::kairosmsg msg;     // 'Message1' 메시지 파일 형식의 'msg' 메시지 선언
  int count = 0;                            // 메시지에 사용될 변수

  while (ros::ok())
  {
    msg.stamp = ros::Time::now();           // 'msg'의 'stamp'에 현재 시간 저장
    msg.data  = count;                      // 'msg'의 'data'에 'count' 값을 저장

    ROS_INFO("send msg = %d", msg.stamp.sec);   // 'stamp.sec' 메시지 출력
    ROS_INFO("send msg = %d", msg.stamp.nsec);  // 'stamp.nsec' 메시지 출력
    ROS_INFO("send msg = %d", msg.data);        // 'data' 메시지 출력

    ros_topic_pub.publish(msg);          // 'msg' 메시지 발행

    ros::spinOnce(); // 노드가 수신하는 메시지를 처리하기 위해 ROS에게 제어를 양보
    loop_rate.sleep(); // 주기를 유지하기 위해 대기
  }

  return 0;
}
