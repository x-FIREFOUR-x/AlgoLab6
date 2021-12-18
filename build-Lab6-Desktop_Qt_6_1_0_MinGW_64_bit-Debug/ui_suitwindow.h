/********************************************************************************
** Form generated from reading UI file 'suitwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUITWINDOW_H
#define UI_SUITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SuitWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *SuitWindow)
    {
        if (SuitWindow->objectName().isEmpty())
            SuitWindow->setObjectName(QString::fromUtf8("SuitWindow"));
        SuitWindow->resize(300, 300);
        pushButton = new QPushButton(SuitWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 50, 150, 150));

        retranslateUi(SuitWindow);

        QMetaObject::connectSlotsByName(SuitWindow);
    } // setupUi

    void retranslateUi(QDialog *SuitWindow)
    {
        SuitWindow->setWindowTitle(QCoreApplication::translate("SuitWindow", "Dialog", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SuitWindow: public Ui_SuitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUITWINDOW_H
