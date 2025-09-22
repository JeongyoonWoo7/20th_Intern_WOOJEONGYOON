#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "ui_mainwindow.h"

#include <QImage>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "vision/qnode.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowDesign; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateCameraFrame();
    void updateRawImage(const QImage &img);
    void updateObjectImage(const QImage &img);
    void updateRedCone(const QImage &img);
    void updateYellowCone(const QImage &img);

private slots:
    void on_btncapture_clicked();
    void on_btnwhiteline_clicked();
    void on_btnblueline_clicked();

private:
    Ui::MainWindowDesign *ui;
    QNode qnode;
    cv::VideoCapture cap;   // 웹캠 캡처 객체
    cv::Mat lastFrame;      // 최근 프레임 저장용
    cv::Mat lastCaptured;   // 마지막 캡처 이미지 저장


    void processLaneDetection(const std::string &mode);
    void processColorDetection();
    std::string judgePosition(const cv::Rect &objectBox, const cv::Size &frameSize);

};

#endif // VISION_MAINWINDOW_HPP