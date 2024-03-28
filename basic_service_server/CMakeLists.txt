cmake_minimum_required(VERSION 3.0.2)
project(basic_service_server)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  tutorial_srvs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES basic_service_server
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_service_server_node src/basic_service_server.cpp)
target_link_libraries(basic_service_server_node ${catkin_LIBRARIES})

#basic_service_server_node라는 실행 가능한 타겟이 
# ${PROJECT_NAME}_EXPORTED_TARGETS와 catkin_EXPORTED_TARGETS에 정의된 다른 모든 타겟에 의존한다는 것
add_dependencies(basic_service_server_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

