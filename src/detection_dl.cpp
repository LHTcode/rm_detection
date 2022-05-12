//
// Created by lihanting on 2022/5/12.
//

#include <rm_detection_dl/detection_dl.h>

namespace rm_detection_dl{
void DetectionDL::onInit()
{
    NODELET_DEBUG("Initializing nodelet...");
}
void DetectionDL::initialize() {

}

PLUGINLIB_EXPORT_CLASS(rm_detection_dl::DetectionDL, nodelet::Nodelet)
}