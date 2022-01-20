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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadWindow
{
public:
    QWidget *centralwidget;
    QScrollBar *verticalScrollBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DownloadWindow)
    {
        if (DownloadWindow->objectName().isEmpty())
            DownloadWindow->setObjectName(QString::fromUtf8("DownloadWindow"));
        DownloadWindow->resize(401, 405);
        centralwidget = new QWidget(DownloadWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(380, 0, 20, 370));
        verticalScrollBar->setOrientation(Qt::Vertical);
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
    } // retranslateUi

};

namespace Ui {
    class DownloadWindow: public Ui_DownloadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADWINDOW_H
