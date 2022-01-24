/********************************************************************************
** Form generated from reading UI file 'downloadwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADWINDOW_H
#define UI_DOWNLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DownloadWindow)
    {
        if (DownloadWindow->objectName().isEmpty())
            DownloadWindow->setObjectName(QString::fromUtf8("DownloadWindow"));
        DownloadWindow->resize(401, 405);
        centralwidget = new QWidget(DownloadWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1, 21, 400, 361));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 359));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 0, 211, 20));
        DownloadWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DownloadWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 401, 26));
        DownloadWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DownloadWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DownloadWindow->setStatusBar(statusbar);

        retranslateUi(DownloadWindow);

        QMetaObject::connectSlotsByName(DownloadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DownloadWindow)
    {
        DownloadWindow->setWindowTitle(QCoreApplication::translate("DownloadWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("DownloadWindow", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\267\320\261\320\265\321\200\320\265\320\266\320\265\320\275\320\275\321\217 \320\263\321\200\320\270 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownloadWindow: public Ui_DownloadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADWINDOW_H
