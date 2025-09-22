#include "vision/mainwindow.hpp"
#include "vision/qnode.hpp"

#include <QApplication>
#include "vision/mainwindow.hpp"

int main(int argc, char **argv) {
    
    QApplication app(argc, argv);

    
    rclcpp::init(argc, argv);

    MainWindow w;
    w.show();

    int ret = app.exec();

    
    rclcpp::shutdown();

    return ret;
}