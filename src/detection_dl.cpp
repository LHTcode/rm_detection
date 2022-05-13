//
// Created by lihanting on 2022/5/12.
//
#include <rm_detection_dl/detection_dl.h>

namespace rm_detection_dl{
void DetectionDL::onInit()
{
    this->it_ = std::make_shared<image_transport::ImageTransport>(this->nh_);
    img_sub_ = it_->subscribeCamera(
            "/galaxy_camera/image_raw" ,
            10,
            &DetectionDL::receiverCallback, this,
            image_transport::TransportHints("raw",ros::TransportHints()));
    img_pub_ = it_->advertiseCamera("test_img_topic", 10);
    // 如何不使用绝对地址，未解决
    std::string input_model_path = "/home/lihanting/current_ws/src/rm_detection_dl/ir_file/8000.xml";
    this->initialize(input_model_path);
}
void DetectionDL::initialize(const std::string input_model_path)
{
    if((fopen(input_model_path.c_str(), "r")) == NULL)
    {
        ROS_ERROR("Can't find file by path:%s",input_model_path.c_str());
        ros::shutdown();
        return;
    }

    InferenceEngine::Core ie_core;  // Initialize inference engine core
    yolox_network_ = ie_core.ReadNetwork(input_model_path);
    InferenceEngine::InputsDataMap net_input_info(yolox_network_.getInputsInfo());
//    auto begin = net_input_info.begin();
//    auto end = net_input_info.end();
//    while(begin != end)
//    {
//        std::cout << (*begin).first << std::endl;
//    }

}

void DetectionDL::receiverCallback(const sensor_msgs::ImageConstPtr& img_msg, const sensor_msgs::CameraInfoConstPtr& img_info_msg)
{
    cv_bridge::CvImageConstPtr cv_cptr = cv_bridge::toCvCopy(img_msg);
//    cv_bridge::CvImageConstPtr cv_cptr = cv_bridge::toCvShare(img_msg);
    cv_cptr->image.copyTo(origin_img_);
    sensor_msgs::ImagePtr output_msg_ptr = cv_bridge::CvImage(std_msgs::Header(),"bgr8", origin_img_).toImageMsg();
    img_pub_.publish(output_msg_ptr, img_info_msg);

}


//PLUGINLIB_EXPORT_CLASS(rm_detection_dl::DetectionDL, nodelet::Nodelet)
}