cmake_minimum_required(VERSION 3.0.2)
project(basic_tutorial)


find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES basic_tutorial
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_node src/basic.cpp)
target_link_libraries(basic_node ${catkin_LIBRARIES})






add_executable(basic_node2 src/basic2.cpp)
target_link_libraries(basic_node2 ${catkin_LIBRARIES})

