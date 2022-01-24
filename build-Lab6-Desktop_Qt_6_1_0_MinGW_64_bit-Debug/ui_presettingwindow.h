/********************************************************************************
** Form generated from reading UI file 'presettingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRESETTINGWINDOW_H
#define UI_PRESETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PresettingWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frameTypeGame;
    QRadioButton *radioButtonTwoPlayers;
    QRadioButton *radioButtonPlayPC;
    QPushButton *ButtonGoGame;
    QPushButton *ButtonBack;
    QLineEdit *Score;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PresettingWindow)
    {
        if (PresettingWindow->objectName().isEmpty())
            PresettingWindow->setObjectName(QString::fromUtf8("PresettingWindow"));
        PresettingWindow->resize(300, 400);
        centralwidget = new QWidget(PresettingWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 20, 161, 30));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));
        frameTypeGame = new QFrame(centralwidget);
        frameTypeGame->setObjectName(QString::fromUtf8("frameTypeGame"));
        frameTypeGame->setGeometry(QRect(5, 50, 301, 41));
        frameTypeGame->setFrameShape(QFrame::StyledPanel);
        frameTypeGame->setFrameShadow(QFrame::Raised);
        radioButtonTwoPlayers = new QRadioButton(frameTypeGame);
        radioButtonTwoPlayers->setObjectName(QString::fromUtf8("radioButtonTwoPlayers"));
        radioButtonTwoPlayers->setGeometry(QRect(20, 10, 101, 20));
        radioButtonTwoPlayers->setStyleSheet(QString::fromUtf8("font: 10pt \"Calibri\";"));
        radioButtonPlayPC = new QRadioButton(frameTypeGame);
        radioButtonPlayPC->setObjectName(QString::fromUtf8("radioButtonPlayPC"));
        radioButtonPlayPC->setGeometry(QRect(130, 10, 171, 20));
        radioButtonPlayPC->setStyleSheet(QString::fromUtf8("font: 10pt \"Calibri\";"));
        radioButtonPlayPC->setChecked(true);
        ButtonGoGame = new QPushButton(centralwidget);
        ButtonGoGame->setObjectName(QString::fromUtf8("ButtonGoGame"));
        ButtonGoGame->setGeometry(QRect(65, 210, 170, 40));
        ButtonBack = new QPushButton(centralwidget);
        ButtonBack->setObjectName(QString::fromUtf8("ButtonBack"));
        ButtonBack->setGeometry(QRect(65, 280, 170, 40));
        Score = new QLineEdit(centralwidget);
        Score->setObjectName(QString::fromUtf8("Score"));
        Score->setGeometry(QRect(140, 150, 100, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(19, 110, 271, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 150, 71, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));
        PresettingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PresettingWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 26));
        PresettingWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PresettingWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PresettingWindow->setStatusBar(statusbar);

        retranslateUi(PresettingWindow);

        QMetaObject::connectSlotsByName(PresettingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PresettingWindow)
    {
        PresettingWindow->setWindowTitle(QCoreApplication::translate("PresettingWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("PresettingWindow", "\320\222\320\270\320\261\320\265\321\200\321\226\321\202\321\214 \321\202\320\270\320\277 \320\263\321\200\320\270:", nullptr));
        radioButtonTwoPlayers->setText(QCoreApplication::translate("PresettingWindow", "\320\224\320\262\320\260 \320\263\321\200\320\260\320\262\321\206\321\226", nullptr));
        radioButtonPlayPC->setText(QCoreApplication::translate("PresettingWindow", "\320\237\321\200\320\276\321\202\320\270 \320\272\320\276\320\274\320\277'\321\216\321\202\320\265\321\200\320\260", nullptr));
        ButtonGoGame->setText(QCoreApplication::translate("PresettingWindow", "\320\223\321\200\320\260\321\202\320\270", nullptr));
        ButtonBack->setText(QCoreApplication::translate("PresettingWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\320\270\321\201\321\217 \320\275\320\260\320\267\320\260\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("PresettingWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\273\321\226\320\274\321\226\321\202 \321\210\321\202\321\200\320\260\321\204\320\275\320\270\321\205 \320\261\320\260\320\273\321\226\320\262", nullptr));
        label_3->setText(QCoreApplication::translate("PresettingWindow", "(1-1000)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PresettingWindow: public Ui_PresettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESETTINGWINDOW_H
