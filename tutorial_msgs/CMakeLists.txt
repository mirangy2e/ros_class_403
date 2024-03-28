cmake_minimum_required(VERSION 3.0.2)
project(tutorial_msgs)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
)
## Generate messages in the 'msg' folder
add_message_files(
  FILES
  TutorialMsg.msg
)


## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tutorial_msgs
 CATKIN_DEPENDS roscpp message_generation std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
