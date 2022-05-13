//
// Created by lihanting on 2022/5/13.
//

# include <ros/ros.h>
#include <rm_detection_dl/detection_dl.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "test_detection_node");
    ros::NodeHandle nh;
    rm_detection_dl::DetectionDL detector(nh);
    detector.onInit();
    ros::spin();
}