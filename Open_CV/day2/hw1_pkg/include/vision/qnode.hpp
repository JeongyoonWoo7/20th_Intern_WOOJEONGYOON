#ifndef QNODE_HPP
#define QNODE_HPP

#include <QThread>
#include <QImage>
#include <QObject>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

class QNode : public QThread {
    Q_OBJECT
public:
    QNode();
    ~QNode();

    void init();
    void run() override;

    void requestCapture();
    void setMode(const std::string &mode);

signals:
    void rawImageReceived(const QImage &img);
    void objectImageReceived(const QImage &img);
    void redConeReceived(const QImage &img);
    void yellowConeReceived(const QImage &img);

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_raw_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_object_;

    QImage cvMatToQImage(const cv::Mat &mat);
};

#endif // QNODE_HPP
