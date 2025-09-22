#include "vision/mainwindow.hpp"
#include "vision/qnode.hpp"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowDesign)
{
    ui->setupUi(this);

    //0 웹캠 2 usb캠
    cap.open(2);
    if (!cap.isOpened()) {
        qWarning("Can't open the camera");
        return;
    }

  
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCameraFrame);
    timer->start(30); 

   


hsvLow["whiteline"]  = Scalar(0, 0, 200);
hsvHigh["whiteline"] = Scalar(179, 40, 255);

hsvLow["blueline"]   = Scalar(100, 150, 50);
hsvHigh["blueline"]  = Scalar(140, 255, 255);

hsvLow["redcone"]    = Scalar(0, 120, 100);
hsvHigh["redcone"]   = Scalar(10, 255, 255);

hsvLow["yellowcone"] = Scalar(20, 100, 100);
hsvHigh["yellowcone"]= Scalar(30, 255, 255);


currentMode = "whiteline";
applyHSVToSliders(currentMode);


connect(ui->hlowslider, &QSlider::valueChanged, this, &MainWindow::updateHSVFromSliders);
connect(ui->hhighslider, &QSlider::valueChanged, this, &MainWindow::updateHSVFromSliders);
connect(ui->slowslider, &QSlider::valueChanged, this, &MainWindow::updateHSVFromSliders);
connect(ui->shighslider, &QSlider::valueChanged, this, &MainWindow::updateHSVFromSliders);
connect(ui->vlowslider, &QSlider::valueChanged, this, &MainWindow::updateHSVFromSliders);
connect(ui->vhighslider, &QSlider::valueChanged, this, &MainWindow::updateHSVFromSliders);

    
}

MainWindow::~MainWindow()
{
    delete ui;
    if (cap.isOpened())
        cap.release();
}

void MainWindow::updateCameraFrame()
{
    Mat frame;
    cap >> frame;
    if (frame.empty()) return;

    
    QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_BGR888);
    ui->cam_raw->setPixmap(QPixmap::fromImage(qimg).scaled(
        ui->cam_raw->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    lastCaptured = frame.clone(); 
}

void MainWindow::on_btncapture_clicked() {
    cap >> lastCaptured;
    if (lastCaptured.empty()) return;

    QImage qimg(lastCaptured.data, lastCaptured.cols, lastCaptured.rows,
                lastCaptured.step, QImage::Format_BGR888);
    ui->cam_raw->setPixmap(QPixmap::fromImage(qimg));

    processLaneDetection(lastCaptured, "whiteline");
    processLaneDetection(lastCaptured, "blueline");

    processConeDetection(lastCaptured);
}


void MainWindow::processLaneDetection(const cv::Mat &frame, const std::string &mode) {
    cv::Mat hsv, mask;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

    inRange(hsv, hsvLow[mode], hsvHigh[mode], mask);
    showMask(mask, (mode == "whiteline" ? ui->whiteline : ui->blueline));

    cv::Mat result = frame.clone();
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    for (auto &c : contours) cv::drawContours(result, std::vector<std::vector<cv::Point>>{c}, -1,
                                              (mode == "whiteline" ? cv::Scalar(255,255,255) : cv::Scalar(255,0,0)), 2);

   
    QImage qres(result.data, result.cols, result.rows, result.step, QImage::Format_BGR888);
    ui->cam_object->setPixmap(QPixmap::fromImage(qres).scaled(ui->cam_object->size(),
                               Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


void MainWindow::processConeDetection(const cv::Mat &frame) {
    Mat hsv;
    cvtColor(frame, hsv, COLOR_BGR2HSV);

    Mat mask_red, mask_yellow;
    inRange(hsv, hsvLow["redcone"], hsvHigh["redcone"], mask_red);
    inRange(hsv, hsvLow["yellowcone"], hsvHigh["yellowcone"], mask_yellow);

    showMask(mask_red, ui->redcone);
    showMask(mask_yellow, ui->yellowcone);

    Mat result = frame.clone();
    std::vector<std::vector<Point>> contours;

 
    findContours(mask_red, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    for (auto &c : contours) {
        Rect box = boundingRect(c);
        if (box.area() < 500) continue; 
        rectangle(result, box, Scalar(0,0,255), 2);
        showZoom(frame, box, ui->redconezoom);
    }
    contours.clear();

   
    findContours(mask_yellow, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    for (auto &c : contours) {
        Rect box = boundingRect(c);
        if (box.area() < 500) continue;
        rectangle(result, box, Scalar(0,255,255), 2);
        showZoom(frame, box, ui->yellowconezoom);
    }

    
    QImage qres(result.data, result.cols, result.rows, result.step, QImage::Format_BGR888);
    ui->cam_object->setPixmap(QPixmap::fromImage(qres).scaled(ui->cam_object->size(),
                               Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::detectCone(const cv::Mat &mask, QLabel *maskLabel, QLabel *zoomLabel)
{
    if (mask.empty()) return;

    
    showMask(mask, maskLabel);

    
    std::vector<std::vector<Point>> contours;
    findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    if (contours.empty()) return;

    auto maxContour = *std::max_element(contours.begin(), contours.end(),
        [](const std::vector<Point> &c1, const std::vector<Point> &c2) {
            return contourArea(c1) < contourArea(c2);
        });

    Rect bbox = boundingRect(maxContour);
    Mat roi = mask(bbox);

    
    QImage qimg(roi.data, roi.cols, roi.rows, roi.step, QImage::Format_Grayscale8);
    zoomLabel->setPixmap(QPixmap::fromImage(qimg).scaled(
        zoomLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}


void MainWindow::showMask(const cv::Mat &mask, QLabel *label) {
    QImage qimg(mask.data, mask.cols, mask.rows, mask.step, QImage::Format_Grayscale8);
    label->setPixmap(QPixmap::fromImage(qimg).scaled(label->size(),
                          Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::showZoom(const cv::Mat &frame, cv::Rect roi, QLabel *label) {
    if (roi.width <= 0 || roi.height <= 0) return;
    cv::Mat zoom = frame(roi).clone();
    cv::resize(zoom, zoom, cv::Size(label->width(), label->height()));
    QImage qimg(zoom.data, zoom.cols, zoom.rows, zoom.step, QImage::Format_BGR888);
    label->setPixmap(QPixmap::fromImage(qimg));
}

void MainWindow::updateStatus(const QString &line, const QString &color, const QString &pos)
{
    if (line == "whiteline" && color == "red")
        ui->whitlelineredstatus->setText(pos);
    else if (line == "whiteline" && color == "yellow")
        ui->whitelineyellowstatus->setText(pos);
    else if (line == "blueline" && color == "red")
        ui->bluelineredstatus->setText(pos);
    else if (line == "blueline" && color == "yellow")
        ui->bluelineyellowstatus->setText(pos);
}


void MainWindow::on_btnwhiteline_clicked() {
    currentMode = "whiteline";
    applyHSVToSliders(currentMode);
}
void MainWindow::on_btnblueline_clicked() {
    currentMode = "blueline";
    applyHSVToSliders(currentMode);
}
void MainWindow::on_btnredcone_clicked() {
    currentMode = "redcone";
    applyHSVToSliders(currentMode);
}
void MainWindow::on_btnyellowcone_clicked() {
    currentMode = "yellowcone";
    applyHSVToSliders(currentMode);
}

void MainWindow::updateHSVFromSliders() {
    hsvConfigs[currentMode] = {
        ui->hlowslider->value(),
        ui->hhighslider->value(),
        ui->slowslider->value(),
        ui->shighslider->value(),
        ui->vlowslider->value(),
        ui->vhighslider->value()
    };
}

void MainWindow::applyHSVToSliders(const std::string &mode) {
    if (hsvConfigs.find(mode) == hsvConfigs.end()) return;
    HSVRange cfg = hsvConfigs[mode];
    ui->hlowslider->setValue(cfg.h_low);
    ui->hhighslider->setValue(cfg.h_high);
    ui->slowslider->setValue(cfg.s_low);
    ui->shighslider->setValue(cfg.s_high);
    ui->vlowslider->setValue(cfg.v_low);
    ui->vhighslider->setValue(cfg.v_high);
}
