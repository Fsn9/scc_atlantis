cmake_minimum_required(VERSION 3.5)
project(scc_atlantis)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# Services
find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/RTL.srv"
  DEPENDENCIES builtin_interfaces
)

# Defining library scc_lib
include_directories(include/scc_atlantis)
add_library(scc_lib STATIC
	src/scc.cpp
  src/robots.cpp
)
# Create run_scc target
add_executable(run_scc src/run_scc.cpp)
# Linking run_scc with scc_lib
target_link_libraries(run_scc scc_lib) # Linking scc_lib with run_scc target
ament_target_dependencies(scc_lib rclcpp) # Linking scc_lib with rclcpp
ament_target_dependencies(run_scc rclcpp std_msgs sensor_msgs mavros_msgs)
target_include_directories(run_scc PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# This added line allows custom services and messages to be used by the target given in the first parameter
rosidl_target_interfaces(run_scc ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(scc_lib ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS
  run_scc
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

# install the launch directory
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

