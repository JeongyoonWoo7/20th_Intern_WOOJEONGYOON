#include "vision/mainwindow.hpp"
#include "vision/qnode.hpp"


QNode::QNode() {}
QNode::~QNode() {}

void QNode::init() {
    
    node_ = rclcpp::Node::make_shared("vision_node");

    sub_raw_ = node_->create_subscription<sensor_msgs::msg::Image>(
    "/image_raw", 10, 
    [this](const sensor_msgs::msg::Image::SharedPtr msg) {
        cv::Mat mat = cv_bridge::toCvCopy(msg, "bgr8")->image;
        emit rawImageReceived(cvMatToQImage(mat));
    });

    sub_object_ = node_->create_subscription<sensor_msgs::msg::Image>(
        "/camera/object", 10,
        [this](const sensor_msgs::msg::Image::SharedPtr msg) {
            cv::Mat mat = cv_bridge::toCvCopy(msg, "bgr8")->image;
            emit objectImageReceived(cvMatToQImage(mat));

            
            cv::Mat hsv, mask_red, mask_yellow;
            cv::cvtColor(mat, hsv, cv::COLOR_BGR2HSV);

            cv::inRange(hsv, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255), mask_red);
            cv::inRange(hsv, cv::Scalar(20, 100, 100), cv::Scalar(30, 255, 255), mask_yellow);

            emit redConeReceived(cvMatToQImage(mask_red));
            emit yellowConeReceived(cvMatToQImage(mask_yellow));
        });
}

void QNode::run() {
    rclcpp::spin(node_);
}

void QNode::requestCapture() {
}

void QNode::setMode(const std::string &mode) {
    RCLCPP_INFO(node_->get_logger(), "Mode set to: %s", mode.c_str());
}

QImage QNode::cvMatToQImage(const cv::Mat &mat) {
    if(mat.type() == CV_8UC3) {
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_BGR888).copy();
    }
    if(mat.type() == CV_8UC1) {
        return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8).copy();
    }
    return QImage();
}
