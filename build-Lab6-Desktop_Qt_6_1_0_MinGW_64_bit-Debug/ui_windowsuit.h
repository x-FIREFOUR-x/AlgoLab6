/********************************************************************************
** Form generated from reading UI file 'windowsuit.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSUIT_H
#define UI_WINDOWSUIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowSuit
{
public:
    QWidget *centralwidget;
    QPushButton *ButtonHeart;
    QPushButton *ButtonClubs;
    QPushButton *ButtonDiamonds;
    QPushButton *ButtonSpades;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *WindowSuit)
    {
        if (WindowSuit->objectName().isEmpty())
            WindowSuit->setObjectName(QString::fromUtf8("WindowSuit"));
        WindowSuit->setEnabled(true);
        WindowSuit->resize(300, 361);
        centralwidget = new QWidget(WindowSuit);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 300, 340));
        ButtonHeart = new QPushButton(centralwidget);
        ButtonHeart->setObjectName(QString::fromUtf8("ButtonHeart"));
        ButtonHeart->setGeometry(QRect(0, 30, 150, 150));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/PNG-cards/hearts.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonHeart->setIcon(icon);
        ButtonHeart->setIconSize(QSize(150, 150));
        ButtonHeart->setAutoRepeatDelay(300);
        ButtonClubs = new QPushButton(centralwidget);
        ButtonClubs->setObjectName(QString::fromUtf8("ButtonClubs"));
        ButtonClubs->setGeometry(QRect(0, 180, 150, 150));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/PNG-cards/clubs.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonClubs->setIcon(icon1);
        ButtonClubs->setIconSize(QSize(150, 150));
        ButtonDiamonds = new QPushButton(centralwidget);
        ButtonDiamonds->setObjectName(QString::fromUtf8("ButtonDiamonds"));
        ButtonDiamonds->setGeometry(QRect(150, 180, 150, 150));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/PNG-cards/diamonds.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonDiamonds->setIcon(icon2);
        ButtonDiamonds->setIconSize(QSize(150, 150));
        ButtonSpades = new QPushButton(centralwidget);
        ButtonSpades->setObjectName(QString::fromUtf8("ButtonSpades"));
        ButtonSpades->setGeometry(QRect(150, 30, 150, 150));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/PNG-cards/spades.png"), QSize(), QIcon::Normal, QIcon::Off);
        ButtonSpades->setIcon(icon3);
        ButtonSpades->setIconSize(QSize(150, 150));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, -1, 121, 30));
        menubar = new QMenuBar(WindowSuit);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 26));
        statusbar = new QStatusBar(WindowSuit);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(0, 0, 3, 21));

        retranslateUi(WindowSuit);

        QMetaObject::connectSlotsByName(WindowSuit);
    } // setupUi

    void retranslateUi(QDialog *WindowSuit)
    {
        WindowSuit->setWindowTitle(QCoreApplication::translate("WindowSuit", "MainWindow", nullptr));
        ButtonHeart->setText(QString());
        ButtonClubs->setText(QString());
        ButtonDiamonds->setText(QString());
        ButtonSpades->setText(QString());
        label->setText(QCoreApplication::translate("WindowSuit", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\274\320\260\321\201\321\202\321\214 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowSuit: public Ui_WindowSuit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSUIT_H
