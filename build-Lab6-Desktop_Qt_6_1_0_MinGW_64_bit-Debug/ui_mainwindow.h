/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ButtonStart;
    QPushButton *ButtonEnd;
    QPushButton *ButtonDownload;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(300, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ButtonStart = new QPushButton(centralwidget);
        ButtonStart->setObjectName(QString::fromUtf8("ButtonStart"));
        ButtonStart->setEnabled(true);
        ButtonStart->setGeometry(QRect(75, 50, 150, 30));
        ButtonEnd = new QPushButton(centralwidget);
        ButtonEnd->setObjectName(QString::fromUtf8("ButtonEnd"));
        ButtonEnd->setGeometry(QRect(75, 240, 150, 30));
        ButtonDownload = new QPushButton(centralwidget);
        ButtonDownload->setObjectName(QString::fromUtf8("ButtonDownload"));
        ButtonDownload->setGeometry(QRect(75, 145, 150, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ButtonStart->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260 \320\263\321\200\320\260", nullptr));
        ButtonEnd->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270 \320\267 \320\263\321\200\320\270", nullptr));
        ButtonDownload->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\263\321\200\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
