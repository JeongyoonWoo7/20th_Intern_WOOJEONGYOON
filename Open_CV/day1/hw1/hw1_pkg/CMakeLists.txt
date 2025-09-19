cmake_minimum_required(VERSION 3.8)
project(opencvtest)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)   

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(opencvtest src/opencvtest.cpp)
ament_target_dependencies(opencvtest rclcpp cv_bridge)

target_link_libraries(opencvtest
  ${OpenCV_LIBS}   
)

install(TARGETS
  opencvtest
  DESTINATION lib/${PROJECT_NAME})
  
  install(DIRECTORY include/
  DESTINATION include/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

