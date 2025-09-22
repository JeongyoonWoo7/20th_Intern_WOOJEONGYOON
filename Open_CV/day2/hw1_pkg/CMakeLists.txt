cmake_minimum_required(VERSION 3.10)
project(vision)

set(CMAKE_CXX_STANDARD 14)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Network)

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)


qt5_wrap_ui(UI_HEADERS
  ui/mainwindow.ui
)

set(MOC_HEADERS
  include/vision/mainwindow.hpp
  include/vision/qnode.hpp
)
qt5_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})


qt5_add_resources(QRC_SOURCES resources/images.qrc)

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/mainwindow.cpp
  src/qnode.cpp
  ${UI_HEADERS}
  ${MOC_SOURCES}
  ${QRC_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}    
)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  sensor_msgs
  cv_bridge
  OpenCV
)

target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets
  Qt5::Core
  Qt5::Gui
  Qt5::Network
  ${OpenCV_LIBS}
)

install(TARGETS ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY include/
  DESTINATION include/
)

ament_package()
