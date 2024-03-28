cmake_minimum_required(VERSION 3.0.2)
project(basic_msg_tutorial)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tutorial_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES basic_msg_tutorial
#  CATKIN_DEPENDS message_runtime roscpp message_generation std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_msg_publish_node src/basic_msg_publish.cpp)
target_link_libraries(basic_msg_publish_node ${catkin_LIBRARIES})
add_dependencies(basic_msg_publish_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(basic_msg_subscribe_node src/basic_msg_subscribe.cpp)
target_link_libraries(basic_msg_subscribe_node ${catkin_LIBRARIES})
add_dependencies(basic_msg_subscribe_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
