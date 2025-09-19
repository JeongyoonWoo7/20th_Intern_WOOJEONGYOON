#include "opencv_udp/mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPixmap>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , rclcpp::Node("image_gui_node")
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);

    
    pub_ = this->create_publisher<std_msgs::msg::String>("image_status", 10);

    sub_ = this->create_subscription<std_msgs::msg::String>(
        "image_status", 10,
        [this](std_msgs::msg::String::SharedPtr msg) {
            
            ui->statusbar->showMessage(QString::fromStdString(msg->data), 3000);
        });

    udpSocket->bind(4999, QUdpSocket::ShareAddress);
    
    connect(udpSocket, &QUdpSocket::readyRead,
        this, &MainWindow::on_btnreceive_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSend_clicked()
{
    Mat img = imread("/home/jy/colcon_ws/src/opencvtest/ball.png");
    if (img.empty()) return;

    std::vector<uchar> buf;
    std::vector<int> params = {cv::IMWRITE_JPEG_QUALITY, 80};
    imencode(".jpg", img, buf, params);

    udpSocket->writeDatagram(reinterpret_cast<const char*>(buf.data()),
                             buf.size(),
                             QHostAddress("192.168.0.20"),
                             5000);

    
    auto msg = std_msgs::msg::String();
    msg.data = "Image sent";
    pub_->publish(msg);
}

void MainWindow::on_btnreceive_clicked()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());

        std::vector<uchar> buf(datagram.begin(), datagram.end());
        Mat img = imdecode(buf, IMREAD_COLOR);

        if (!img.empty()) {
            QImage qimg(img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
            ui->imageLabel->setPixmap(QPixmap::fromImage(qimg).scaled(
                ui->imageLabel->size(), Qt::KeepAspectRatio));
        }
    }
}
