cmake_minimum_required(VERSION 3.0.2)
project(rm_detection_dl)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    dynamic_reconfigure
    image_transport
    cv_bridge
    roslaunch
)

find_package(InferenceEngine REQUIRED)
find_package(ngraph REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS)

# 声明这个catkin包的运行时依赖
catkin_package(
        CATKIN_DEPENDS
        roscpp
        std_msgs
        dynamic_reconfigure
        image_transport
        cv_bridge
        roslaunch
)
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

# 生成插件库
#add_library(rm_detection_dl src/detection_dl.cpp)

add_executable(detector_dl src/detection_dl_node.cpp src/detection_dl.cpp)

target_link_libraries(  # 链接相关库
    detector_dl
    ${InferenceEngine_LIBRARIES}
    ${ngraph_LIBRARIES}
    ${catkin_LIBRARIES}
)

if(catkin_EXPORTED_LIBRARIES)
    add_dependencies(detector_dl ${catkin_EXPORTED_LIBRARIES})
endif()


