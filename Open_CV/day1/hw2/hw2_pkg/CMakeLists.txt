cmake_minimum_required(VERSION 3.10)
project(opencv_udp)

set(CMAKE_CXX_STANDARD 14)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Network)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)   
set(CMAKE_AUTOUIC OFF)


qt5_wrap_ui(UI_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/ui/mainwindow.ui
)


set(MOC_HEADERS
  include/opencv_udp/mainwindow.hpp
  include/opencv_udp/qnode.hpp
)
qt5_wrap_cpp(MOC_SOURCES ${MOC_HEADERS})

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/mainwindow.cpp
  src/qnode.cpp
  ${UI_HEADERS}
  ${MOC_SOURCES}
  resources/images.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_BINARY_DIR}
)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  std_msgs
  OpenCV
)

target_link_libraries(${PROJECT_NAME}
  Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network
  ${OpenCV_LIBS}
)

install(TARGETS ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

