/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "gameboard.h"

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QAction *CloseEnd;
    QAction *SaveAs;
    QAction *Save;
    QWidget *centralwidget;
    GameBoard *graphicsView;
    QLabel *CountCardDeck;
    QLabel *labelScore1;
    QLabel *labelScore2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *MaxScore;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(900, 550);
        CloseEnd = new QAction(GameWindow);
        CloseEnd->setObjectName(QString::fromUtf8("CloseEnd"));
        SaveAs = new QAction(GameWindow);
        SaveAs->setObjectName(QString::fromUtf8("SaveAs"));
        Save = new QAction(GameWindow);
        Save->setObjectName(QString::fromUtf8("Save"));
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new GameBoard(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 900, 500));
        CountCardDeck = new QLabel(centralwidget);
        CountCardDeck->setObjectName(QString::fromUtf8("CountCardDeck"));
        CountCardDeck->setGeometry(QRect(0, 230, 51, 31));
        QFont font;
        font.setPointSize(18);
        CountCardDeck->setFont(font);
        CountCardDeck->setStyleSheet(QString::fromUtf8("color: red;"));
        CountCardDeck->setLineWidth(1);
        CountCardDeck->setAlignment(Qt::AlignCenter);
        CountCardDeck->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        labelScore1 = new QLabel(centralwidget);
        labelScore1->setObjectName(QString::fromUtf8("labelScore1"));
        labelScore1->setGeometry(QRect(850, 200, 51, 16));
        labelScore1->setStyleSheet(QString::fromUtf8("color:yellow;"));
        labelScore2 = new QLabel(centralwidget);
        labelScore2->setObjectName(QString::fromUtf8("labelScore2"));
        labelScore2->setGeometry(QRect(850, 280, 55, 16));
        labelScore2->setStyleSheet(QString::fromUtf8("color:yellow;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(750, 200, 91, 20));
        label->setStyleSheet(QString::fromUtf8("color:yellow;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(750, 280, 91, 16));
        label_2->setStyleSheet(QString::fromUtf8("color:yellow;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(800, 240, 51, 16));
        label_3->setStyleSheet(QString::fromUtf8("color:yellow;"));
        MaxScore = new QLabel(centralwidget);
        MaxScore->setObjectName(QString::fromUtf8("MaxScore"));
        MaxScore->setGeometry(QRect(850, 240, 55, 16));
        MaxScore->setStyleSheet(QString::fromUtf8("color:yellow;"));
        GameWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(GameWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GameWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(GameWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        GameWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(CloseEnd);
        menu->addAction(SaveAs);
        menu->addAction(Save);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "MainWindow", nullptr));
        CloseEnd->setText(QCoreApplication::translate("GameWindow", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270 \320\263\321\200\321\203", nullptr));
        SaveAs->setText(QCoreApplication::translate("GameWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \321\217\320\272", nullptr));
        Save->setText(QCoreApplication::translate("GameWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", nullptr));
        CountCardDeck->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        labelScore1->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        labelScore2->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("GameWindow", "\320\236\321\207\320\272\320\270 1 \320\263\321\200\320\260\320\262\321\206\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("GameWindow", "\320\236\321\207\320\272\320\270 2 \320\263\321\200\320\260\320\262\321\206\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("GameWindow", "\320\223\321\200\320\260 \320\264\320\276:", nullptr));
        MaxScore->setText(QCoreApplication::translate("GameWindow", "0", nullptr));
        menu->setTitle(QCoreApplication::translate("GameWindow", "\320\234\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
