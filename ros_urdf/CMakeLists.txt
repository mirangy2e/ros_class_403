cmake_minimum_required(VERSION 3.0.2)
project(ros_urdf)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rviz
  tf
  urdf
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_urdf
#  CATKIN_DEPENDS geometry_msgs roscpp rviz tf urdf
#  DEPENDS system_lib
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

