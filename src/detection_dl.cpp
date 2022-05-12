//
// Created by lihanting on 2022/5/12.
//
#include <rm_detection_dl/detection_dl.h>

namespace rm_detection_dl{
void DetectionDL::onInit()
{
    NODELET_DEBUG("Initializing nodelet...");
    auto& nh = getPrivateNodeHandle();
    this->it_ = std::make_shared<image_transport::ImageTransport>(nh);
    img_sub_ = it_->subscribeCamera(
            "/galaxy_camera/image_raw" ,
            10,
            &DetectionDL::receiverCallback, this,
            image_transport::TransportHints("raw",ros::TransportHints()));

}
void DetectionDL::initialize()
{

}
void DetectionDL::receiverCallback(const sensor_msgs::ImageConstPtr& img_msg, const sensor_msgs::CameraInfoConstPtr& img_info_msg)
{
    cv_bridge::CvImageConstPtr cv_cptr = cv_bridge::toCvCopy(img_msg);
//    cv_bridge::CvImageConstPtr cv_cptr = cv_bridge::toCvShare(img_msg);
    cv_cptr->image.copyTo(origin_img_);
}


PLUGINLIB_EXPORT_CLASS(rm_detection_dl::DetectionDL, nodelet::Nodelet)
}