/********************************************************************************
** Form generated from reading UI file 'windowrank.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWRANK_H
#define UI_WINDOWRANK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_WindowRank
{
public:
    QRadioButton *radioButtonTwo;
    QLabel *label;
    QRadioButton *radioButtonThree;
    QRadioButton *radioButtonFour;
    QRadioButton *radioButtonFive;
    QRadioButton *radioButtonSix;
    QRadioButton *radioButtonSeven;
    QRadioButton *radioButtonEight;
    QRadioButton *radioButtonNine;
    QRadioButton *radioButtonTen;
    QRadioButton *radioButtonJack;
    QRadioButton *radioButtonQueen;
    QRadioButton *radioButtonKing;
    QRadioButton *radioButtonAce;

    void setupUi(QDialog *WindowRank)
    {
        if (WindowRank->objectName().isEmpty())
            WindowRank->setObjectName(QString::fromUtf8("WindowRank"));
        WindowRank->resize(370, 211);
        radioButtonTwo = new QRadioButton(WindowRank);
        radioButtonTwo->setObjectName(QString::fromUtf8("radioButtonTwo"));
        radioButtonTwo->setGeometry(QRect(40, 60, 95, 20));
        label = new QLabel(WindowRank);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 121, 16));
        radioButtonThree = new QRadioButton(WindowRank);
        radioButtonThree->setObjectName(QString::fromUtf8("radioButtonThree"));
        radioButtonThree->setGeometry(QRect(40, 90, 95, 20));
        radioButtonFour = new QRadioButton(WindowRank);
        radioButtonFour->setObjectName(QString::fromUtf8("radioButtonFour"));
        radioButtonFour->setGeometry(QRect(40, 120, 95, 20));
        radioButtonFive = new QRadioButton(WindowRank);
        radioButtonFive->setObjectName(QString::fromUtf8("radioButtonFive"));
        radioButtonFive->setGeometry(QRect(40, 150, 95, 20));
        radioButtonSix = new QRadioButton(WindowRank);
        radioButtonSix->setObjectName(QString::fromUtf8("radioButtonSix"));
        radioButtonSix->setGeometry(QRect(40, 180, 95, 20));
        radioButtonSeven = new QRadioButton(WindowRank);
        radioButtonSeven->setObjectName(QString::fromUtf8("radioButtonSeven"));
        radioButtonSeven->setGeometry(QRect(160, 60, 95, 20));
        radioButtonEight = new QRadioButton(WindowRank);
        radioButtonEight->setObjectName(QString::fromUtf8("radioButtonEight"));
        radioButtonEight->setGeometry(QRect(160, 90, 95, 20));
        radioButtonEight->setCheckable(true);
        radioButtonNine = new QRadioButton(WindowRank);
        radioButtonNine->setObjectName(QString::fromUtf8("radioButtonNine"));
        radioButtonNine->setGeometry(QRect(160, 120, 95, 20));
        radioButtonTen = new QRadioButton(WindowRank);
        radioButtonTen->setObjectName(QString::fromUtf8("radioButtonTen"));
        radioButtonTen->setGeometry(QRect(160, 150, 95, 20));
        radioButtonJack = new QRadioButton(WindowRank);
        radioButtonJack->setObjectName(QString::fromUtf8("radioButtonJack"));
        radioButtonJack->setGeometry(QRect(280, 60, 95, 20));
        radioButtonQueen = new QRadioButton(WindowRank);
        radioButtonQueen->setObjectName(QString::fromUtf8("radioButtonQueen"));
        radioButtonQueen->setGeometry(QRect(280, 90, 95, 20));
        radioButtonKing = new QRadioButton(WindowRank);
        radioButtonKing->setObjectName(QString::fromUtf8("radioButtonKing"));
        radioButtonKing->setGeometry(QRect(280, 120, 95, 20));
        radioButtonAce = new QRadioButton(WindowRank);
        radioButtonAce->setObjectName(QString::fromUtf8("radioButtonAce"));
        radioButtonAce->setGeometry(QRect(280, 150, 95, 20));

        retranslateUi(WindowRank);

        QMetaObject::connectSlotsByName(WindowRank);
    } // setupUi

    void retranslateUi(QDialog *WindowRank)
    {
        WindowRank->setWindowTitle(QCoreApplication::translate("WindowRank", "Dialog", nullptr));
        radioButtonTwo->setText(QCoreApplication::translate("WindowRank", "2", nullptr));
        label->setText(QCoreApplication::translate("WindowRank", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \321\200\320\260\320\275\320\263 \320\272\320\260\321\200\321\202\320\270", nullptr));
        radioButtonThree->setText(QCoreApplication::translate("WindowRank", "3", nullptr));
        radioButtonFour->setText(QCoreApplication::translate("WindowRank", "4", nullptr));
        radioButtonFive->setText(QCoreApplication::translate("WindowRank", "5", nullptr));
        radioButtonSix->setText(QCoreApplication::translate("WindowRank", "6", nullptr));
        radioButtonSeven->setText(QCoreApplication::translate("WindowRank", "7", nullptr));
        radioButtonEight->setText(QCoreApplication::translate("WindowRank", "8", nullptr));
        radioButtonNine->setText(QCoreApplication::translate("WindowRank", "9", nullptr));
        radioButtonTen->setText(QCoreApplication::translate("WindowRank", "10", nullptr));
        radioButtonJack->setText(QCoreApplication::translate("WindowRank", "\320\222\320\260\320\273\321\224\321\202", nullptr));
        radioButtonQueen->setText(QCoreApplication::translate("WindowRank", "\320\224\320\260\320\274\320\260", nullptr));
        radioButtonKing->setText(QCoreApplication::translate("WindowRank", "\320\232\320\276\321\200\320\276\320\273\321\214", nullptr));
        radioButtonAce->setText(QCoreApplication::translate("WindowRank", "\320\242\321\203\320\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowRank: public Ui_WindowRank {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWRANK_H
