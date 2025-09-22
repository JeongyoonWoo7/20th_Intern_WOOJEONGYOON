#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "ui_mainwindow.h"

#include <QImage>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include "vision/qnode.hpp"
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowDesign; }
QT_END_NAMESPACE

struct HSVRange {
    int h_low, h_high;
    int s_low, s_high;
    int v_low, v_high;
};



class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateCameraFrame();
    void on_btncapture_clicked();

    
    void on_btnwhiteline_clicked();
    void on_btnblueline_clicked();
    void on_btnredcone_clicked();
    void on_btnyellowcone_clicked();

private:
    Ui::MainWindowDesign *ui;
    cv::VideoCapture cap;
    cv::Mat lastCaptured;

    
    

   
    std::string currentMode;
    std::map<std::string, cv::Scalar> hsvLow;
    std::map<std::string, cv::Scalar> hsvHigh;
    std::map<std::string, HSVRange> hsvConfigs;

    
    void updateHSVFromSliders();
    void applyHSVToSliders(const std::string &mode);

    
    void processLaneDetection(const cv::Mat &frame, const std::string &mode);
    void processConeDetection(const cv::Mat &frame);

    
    void showMask(const cv::Mat &mask, QLabel *label);
    void showZoom(const cv::Mat &frame, cv::Rect roi, QLabel *label);
    void detectCone(const cv::Mat &mask, QLabel *maskLabel, QLabel *zoomLabel);

    void updateStatus(const QString &line, const QString &color, const QString &pos);
};

#endif // MAINWINDOW_HPP