//
// Created by lihanting on 2022/5/12.
//
#pragma once
//#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>
#include <pluginlib/class_list_macros.h>
#include <inference_engine.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <std_msgs/String.h>
namespace rm_detection_dl {
class DetectionDL
{
public:
    DetectionDL() = default;
    DetectionDL(ros::NodeHandle nh) : nh_(nh){}
    void initialize();

private:
    void onInit();
    void receiverCallback(const sensor_msgs::ImageConstPtr& img_msg, const sensor_msgs::CameraInfoConstPtr& img_info_msg);
    ros::NodeHandle nh_;
    std::shared_ptr<image_transport::ImageTransport> it_;
    image_transport::CameraSubscriber img_sub_;
    cv::Mat origin_img_;
    ros::Publisher test_pub_;
};
}
