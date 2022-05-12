cmake_minimum_required(VERSION 3.0.2)
project(rm_detection_dl)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  nodelet
  roscpp
  std_msgs
)

find_package(InferenceEngine REQUIRED)
find_package(ngraph REQUIRED)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
)

add_library(    # 生成插件库
        rm_detection_dl src/detection_dl.cpp
)
target_link_libraries(  # 链接相关库
    rm_detection_dl
        ${InferenceEngine_LIBRARIES}
        ${ngraph_LIBRARIES}
)
if(catkin_EXPORTED_LIBRARIES)
    add_dependencies(rm_detection_dl ${catkin_EXPORTED_LIBRARIES})
endif()