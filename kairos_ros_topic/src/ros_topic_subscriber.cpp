#include "ros/ros.h"                          // ROS 기본 헤더 파일
#include "kairos_ros_topic/kairosmsg.h"    // MsgTutorial 메시지 파일 헤더. 이 헤더 파일은 패키지를 빌드할 때 자동으로 생성됩니다.

void msgCallback(const kairos_ros_topic::kairosmsg::ConstPtr& msg)
{
  ROS_INFO("recieve msg = %d", msg->stamp.sec);   // 'stamp.sec' 메시지 출력
  ROS_INFO("recieve msg = %d", msg->stamp.nsec);  // 'stamp.nsec' 메시지 출력
  ROS_INFO("recieve msg = %d", msg->data);        // 'data' 메시지 출력
}

int main(int argc, char **argv)                         // 노드 메인 함수
{
  ros::init(argc, argv, "kairos_topic_subscriber");            // 노드 이름 초기화

  ros::NodeHandle nh;                                   // ROS 시스템과 통신하기 위한 노드 핸들 선언

  ros::Subscriber ros_topic_sub = nh.subscribe("kairos_topic_msg", 100, msgCallback);

  ros::spin();

  return 0;
}
