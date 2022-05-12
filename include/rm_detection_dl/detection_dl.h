//
// Created by lihanting on 2022/5/12.
//
#pragma once
#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <pluginlib/class_list_macros.h>
#include <inference_engine.hpp>
#include <vector>


namespace rm_detection_dl {
class DetectionDL : public nodelet::Nodelet
{
public:
    DetectionDL() = default;
    void initialize();


private:
    virtual void onInit();
};
}
