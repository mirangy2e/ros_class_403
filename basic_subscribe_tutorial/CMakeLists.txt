cmake_minimum_required(VERSION 3.0.2)
project(basic_subscribe_tutorial)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES basic_subscribe_tutorial
#  CATKIN_DEPENDS geometry_msgs roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

# add_executable(basic_subscribe_node src/basic_subscribe.cpp)
# target_link_libraries(basic_subscribe_node ${catkin_LIBRARIES})
