cmake_minimum_required(VERSION 3.0.2)
project(basic_publish_tutorial)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES basic_publish_tutorial
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_publish_node src/basic_publish.cpp)
target_link_libraries(basic_publish_node ${catkin_LIBRARIES})
