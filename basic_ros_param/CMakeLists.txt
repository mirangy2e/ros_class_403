cmake_minimum_required(VERSION 3.0.2)
project(basic_ros_param)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_service_files(
  FILES
  CalculateSrv.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES basic_ros_param
 CATKIN_DEPENDS message_generation roscpp std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(service_server_param src/service_server_param.cpp)
target_link_libraries(service_server_param ${catkin_LIBRARIES})
add_dependencies(service_server_param ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(service_client_param src/service_client_param.cpp)
target_link_libraries(service_client_param ${catkin_LIBRARIES})
add_dependencies(service_client_param ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

