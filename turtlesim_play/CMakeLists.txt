cmake_minimum_required(VERSION 3.0.2)
project(turtlesim_play)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES turtlesim_play
#  CATKIN_DEPENDS geometry_msgs roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(circle_publish_node src/circle_publish.cpp)
target_link_libraries(circle_publish_node ${catkin_LIBRARIES})