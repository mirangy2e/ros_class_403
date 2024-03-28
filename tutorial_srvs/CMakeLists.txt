cmake_minimum_required(VERSION 3.0.2)
project(tutorial_srvs)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
)

add_service_files(
  FILES
  TutorialSrv.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs  
)

catkin_package(

 CATKIN_DEPENDS roscpp message_generation std_msgs message_runtime

)

include_directories(

  ${catkin_INCLUDE_DIRS}
)

