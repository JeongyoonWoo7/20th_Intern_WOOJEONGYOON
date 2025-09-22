/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QLabel *cam_object;
    QLabel *whiteline;
    QLabel *cam_raw;
    QLabel *redcone;
    QLabel *yellowcone;
    QLabel *redconezoom;
    QLabel *blueline;
    QLabel *yellowconezoom;
    QRadioButton *btnwhiteline;
    QRadioButton *btnblueline;
    QRadioButton *btnredcone;
    QRadioButton *btnyellowcone;
    QSlider *hhighslider;
    QSlider *hlowslider;
    QSlider *shighslider;
    QSlider *slowslider;
    QSlider *vhighslider;
    QSlider *vlowslider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *whitlelineredstatus;
    QLabel *whitelineyellowstatus;
    QLabel *bluelineredstatus;
    QLabel *bluelineyellowstatus;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *btncapture;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1614, 793);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cam_object = new QLabel(centralwidget);
        cam_object->setObjectName(QString::fromUtf8("cam_object"));
        cam_object->setGeometry(QRect(390, 10, 371, 231));
        cam_object->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        whiteline = new QLabel(centralwidget);
        whiteline->setObjectName(QString::fromUtf8("whiteline"));
        whiteline->setGeometry(QRect(770, 10, 371, 231));
        whiteline->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        cam_raw = new QLabel(centralwidget);
        cam_raw->setObjectName(QString::fromUtf8("cam_raw"));
        cam_raw->setGeometry(QRect(10, 10, 371, 231));
        cam_raw->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        redcone = new QLabel(centralwidget);
        redcone->setObjectName(QString::fromUtf8("redcone"));
        redcone->setGeometry(QRect(10, 270, 371, 231));
        redcone->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        yellowcone = new QLabel(centralwidget);
        yellowcone->setObjectName(QString::fromUtf8("yellowcone"));
        yellowcone->setGeometry(QRect(390, 270, 371, 231));
        yellowcone->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        redconezoom = new QLabel(centralwidget);
        redconezoom->setObjectName(QString::fromUtf8("redconezoom"));
        redconezoom->setGeometry(QRect(770, 270, 371, 231));
        redconezoom->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        blueline = new QLabel(centralwidget);
        blueline->setObjectName(QString::fromUtf8("blueline"));
        blueline->setGeometry(QRect(1150, 10, 371, 231));
        blueline->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        yellowconezoom = new QLabel(centralwidget);
        yellowconezoom->setObjectName(QString::fromUtf8("yellowconezoom"));
        yellowconezoom->setGeometry(QRect(1150, 270, 371, 231));
        yellowconezoom->setStyleSheet(QString::fromUtf8("QLabel { background-color: grey; }"));
        btnwhiteline = new QRadioButton(centralwidget);
        btnwhiteline->setObjectName(QString::fromUtf8("btnwhiteline"));
        btnwhiteline->setGeometry(QRect(30, 560, 112, 23));
        btnblueline = new QRadioButton(centralwidget);
        btnblueline->setObjectName(QString::fromUtf8("btnblueline"));
        btnblueline->setGeometry(QRect(30, 610, 112, 23));
        btnredcone = new QRadioButton(centralwidget);
        btnredcone->setObjectName(QString::fromUtf8("btnredcone"));
        btnredcone->setGeometry(QRect(30, 660, 112, 23));
        btnyellowcone = new QRadioButton(centralwidget);
        btnyellowcone->setObjectName(QString::fromUtf8("btnyellowcone"));
        btnyellowcone->setGeometry(QRect(30, 710, 112, 23));
        hhighslider = new QSlider(centralwidget);
        hhighslider->setObjectName(QString::fromUtf8("hhighslider"));
        hhighslider->setGeometry(QRect(270, 610, 160, 16));
        hhighslider->setOrientation(Qt::Horizontal);
        hlowslider = new QSlider(centralwidget);
        hlowslider->setObjectName(QString::fromUtf8("hlowslider"));
        hlowslider->setGeometry(QRect(270, 670, 160, 16));
        hlowslider->setOrientation(Qt::Horizontal);
        shighslider = new QSlider(centralwidget);
        shighslider->setObjectName(QString::fromUtf8("shighslider"));
        shighslider->setGeometry(QRect(520, 610, 160, 16));
        shighslider->setOrientation(Qt::Horizontal);
        slowslider = new QSlider(centralwidget);
        slowslider->setObjectName(QString::fromUtf8("slowslider"));
        slowslider->setGeometry(QRect(520, 670, 160, 16));
        slowslider->setOrientation(Qt::Horizontal);
        vhighslider = new QSlider(centralwidget);
        vhighslider->setObjectName(QString::fromUtf8("vhighslider"));
        vhighslider->setGeometry(QRect(750, 610, 160, 16));
        vhighslider->setOrientation(Qt::Horizontal);
        vlowslider = new QSlider(centralwidget);
        vlowslider->setObjectName(QString::fromUtf8("vlowslider"));
        vlowslider->setGeometry(QRect(750, 670, 160, 16));
        vlowslider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 560, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(570, 560, 67, 17));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(800, 560, 91, 17));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(1030, 600, 67, 17));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1020, 660, 67, 17));
        whitlelineredstatus = new QLabel(centralwidget);
        whitlelineredstatus->setObjectName(QString::fromUtf8("whitlelineredstatus"));
        whitlelineredstatus->setGeometry(QRect(1140, 600, 67, 17));
        whitelineyellowstatus = new QLabel(centralwidget);
        whitelineyellowstatus->setObjectName(QString::fromUtf8("whitelineyellowstatus"));
        whitelineyellowstatus->setGeometry(QRect(1140, 660, 67, 17));
        bluelineredstatus = new QLabel(centralwidget);
        bluelineredstatus->setObjectName(QString::fromUtf8("bluelineredstatus"));
        bluelineredstatus->setGeometry(QRect(1270, 600, 67, 17));
        bluelineyellowstatus = new QLabel(centralwidget);
        bluelineyellowstatus->setObjectName(QString::fromUtf8("bluelineyellowstatus"));
        bluelineyellowstatus->setGeometry(QRect(1270, 660, 67, 17));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(1140, 550, 67, 17));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(1270, 550, 67, 17));
        btncapture = new QPushButton(centralwidget);
        btncapture->setObjectName(QString::fromUtf8("btncapture"));
        btncapture->setGeometry(QRect(740, 730, 131, 41));
        btncapture->setStyleSheet(QString::fromUtf8("background-color: red;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 610, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 670, 67, 17));
        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QCoreApplication::translate("MainWindowDesign", "QRosApp", nullptr));
        action_Quit->setText(QCoreApplication::translate("MainWindowDesign", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        action_Quit->setShortcut(QCoreApplication::translate("MainWindowDesign", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Preferences->setText(QCoreApplication::translate("MainWindowDesign", "&Preferences", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindowDesign", "&About", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindowDesign", "About &Qt", nullptr));
        cam_object->setText(QCoreApplication::translate("MainWindowDesign", "cam_object", nullptr));
        whiteline->setText(QCoreApplication::translate("MainWindowDesign", "whiteline", nullptr));
        cam_raw->setText(QCoreApplication::translate("MainWindowDesign", "cam_raw", nullptr));
        redcone->setText(QCoreApplication::translate("MainWindowDesign", "redcone", nullptr));
        yellowcone->setText(QCoreApplication::translate("MainWindowDesign", "yellowcone", nullptr));
        redconezoom->setText(QCoreApplication::translate("MainWindowDesign", "redconezoom", nullptr));
        blueline->setText(QCoreApplication::translate("MainWindowDesign", "blueline", nullptr));
        yellowconezoom->setText(QCoreApplication::translate("MainWindowDesign", "yellowconezoom", nullptr));
        btnwhiteline->setText(QCoreApplication::translate("MainWindowDesign", "whiteline", nullptr));
        btnblueline->setText(QCoreApplication::translate("MainWindowDesign", "blueline", nullptr));
        btnredcone->setText(QCoreApplication::translate("MainWindowDesign", "redcone", nullptr));
        btnyellowcone->setText(QCoreApplication::translate("MainWindowDesign", "yellowcone", nullptr));
        label->setText(QCoreApplication::translate("MainWindowDesign", "\354\203\211\354\241\260 H", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowDesign", "\354\261\204\353\217\204 S", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindowDesign", "\353\260\235\352\270\260(\353\252\205\353\217\204) V", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowDesign", "red", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindowDesign", "yellow", nullptr));
        whitlelineredstatus->setText(QCoreApplication::translate("MainWindowDesign", "TextLabel", nullptr));
        whitelineyellowstatus->setText(QCoreApplication::translate("MainWindowDesign", "TextLabel", nullptr));
        bluelineredstatus->setText(QCoreApplication::translate("MainWindowDesign", "TextLabel", nullptr));
        bluelineyellowstatus->setText(QCoreApplication::translate("MainWindowDesign", "TextLabel", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindowDesign", "whiteline", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindowDesign", "blueline", nullptr));
        btncapture->setText(QCoreApplication::translate("MainWindowDesign", "\354\260\260\354\271\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowDesign", "high", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowDesign", "low", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
