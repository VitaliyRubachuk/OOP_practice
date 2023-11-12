/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
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
    QPushButton *FListButton;
    QPushButton *exit;
    QPushButton *openPaymentDialogButton;
    QPushButton *openNewObjectDialogButton;
    QPushButton *SListButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1065, 839);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        FListButton = new QPushButton(centralwidget);
        FListButton->setObjectName("FListButton");
        FListButton->setGeometry(QRect(70, 300, 181, 51));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(640, 350, 91, 41));
        openPaymentDialogButton = new QPushButton(centralwidget);
        openPaymentDialogButton->setObjectName("openPaymentDialogButton");
        openPaymentDialogButton->setGeometry(QRect(270, 180, 191, 51));
        openNewObjectDialogButton = new QPushButton(centralwidget);
        openNewObjectDialogButton->setObjectName("openNewObjectDialogButton");
        openNewObjectDialogButton->setGeometry(QRect(70, 180, 181, 51));
        SListButton = new QPushButton(centralwidget);
        SListButton->setObjectName("SListButton");
        SListButton->setGeometry(QRect(270, 300, 191, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1065, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        FListButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\262\320\265\321\201\321\202\320\270 \321\201\320\277\320\270\321\201\320\276\320\272 1", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\205\321\226\320\264", nullptr));
        openPaymentDialogButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\265\320\275\320\275\321\217 \320\276\320\261'\321\224\320\272\321\202\321\203 2", nullptr));
        openNewObjectDialogButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\265\320\275\320\275\321\217 \320\276\320\261'\321\224\320\272\321\202\321\203 1", nullptr));
        SListButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\262\320\265\321\201\321\202\320\270 \321\201\320\277\320\270\321\201\320\276\320\272 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
