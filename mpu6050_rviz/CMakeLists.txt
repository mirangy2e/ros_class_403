cmake_minimum_required(VERSION 3.0.2)
project(mpu6050_rviz)
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
  serial
  std_msgs
  std_srvs
  tf
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES mpu6050_rviz
 CATKIN_DEPENDS geometry_msgs roscpp sensor_msgs serial std_msgs std_srvs tf
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
add_executable(MPU6050_rviz_pub src/MPU6050_rviz_pub.cpp)
target_link_libraries(MPU6050_rviz_pub ${catkin_LIBRARIES})
