cmake_minimum_required(VERSION 3.0.2)
project(kairos_ros_topic)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(
  FILES
  kairosmsg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES kairos_ros_topic
 CATKIN_DEPENDS message_generation roscpp std_msgs message_runtime 
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(kairos_topic_publisher src/ros_topic_publisher.cpp)
target_link_libraries(kairos_topic_publisher ${catkin_LIBRARIES})
add_dependencies(kairos_topic_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(kairos_topic_subscriber src/ros_topic_subscriber.cpp)
target_link_libraries(kairos_topic_subscriber ${catkin_LIBRARIES})
add_dependencies(kairos_topic_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
