/********************************************************************************
** Form generated from reading UI file 'savewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEWINDOW_H
#define UI_SAVEWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *labelFilename;
    QPushButton *SaveButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SaveWindow)
    {
        if (SaveWindow->objectName().isEmpty())
            SaveWindow->setObjectName(QString::fromUtf8("SaveWindow"));
        SaveWindow->resize(300, 200);
        centralwidget = new QWidget(SaveWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelFilename = new QLineEdit(centralwidget);
        labelFilename->setObjectName(QString::fromUtf8("labelFilename"));
        labelFilename->setGeometry(QRect(30, 70, 240, 22));
        labelFilename->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        SaveButton = new QPushButton(centralwidget);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));
        SaveButton->setGeometry(QRect(80, 120, 140, 30));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 251, 20));
        SaveWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SaveWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 26));
        SaveWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SaveWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SaveWindow->setStatusBar(statusbar);

        retranslateUi(SaveWindow);

        QMetaObject::connectSlotsByName(SaveWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SaveWindow)
    {
        SaveWindow->setWindowTitle(QCoreApplication::translate("SaveWindow", "MainWindow", nullptr));
        SaveButton->setText(QCoreApplication::translate("SaveWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\263\321\200\321\203", nullptr));
        label->setText(QCoreApplication::translate("SaveWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\275\320\260\320\267\320\262\321\203 \320\267\320\261\320\265\321\200\320\265\320\266\320\265\320\275\320\275\321\217 \320\263\321\200\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveWindow: public Ui_SaveWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEWINDOW_H
