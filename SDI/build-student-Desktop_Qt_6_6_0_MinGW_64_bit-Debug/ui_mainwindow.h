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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QLabel *lnameLabel;
    QLineEdit *lnameLineEdit;
    QLabel *fnameLabel;
    QLineEdit *fnameLineEdit;
    QLabel *mnameLabel;
    QLineEdit *mnameLineEdit;
    QLabel *birthLabel;
    QLineEdit *birthLineEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneLineEdit;
    QLabel *facultyLabel;
    QLabel *courseLabel;
    QLabel *groupLabel;
    QLineEdit *facultyLineEdit;
    QLineEdit *courseLineEdit;
    QLineEdit *groupLineEdit;
    QPushButton *createObjectButton;
    QPushButton *displayObjectButton;
    QPushButton *exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1103, 839);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        idLabel = new QLabel(centralwidget);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(80, 100, 49, 16));
        idLineEdit = new QLineEdit(centralwidget);
        idLineEdit->setObjectName("idLineEdit");
        idLineEdit->setGeometry(QRect(30, 70, 113, 22));
        lnameLabel = new QLabel(centralwidget);
        lnameLabel->setObjectName("lnameLabel");
        lnameLabel->setGeometry(QRect(190, 100, 61, 16));
        lnameLineEdit = new QLineEdit(centralwidget);
        lnameLineEdit->setObjectName("lnameLineEdit");
        lnameLineEdit->setGeometry(QRect(160, 70, 113, 22));
        fnameLabel = new QLabel(centralwidget);
        fnameLabel->setObjectName("fnameLabel");
        fnameLabel->setGeometry(QRect(330, 100, 61, 16));
        fnameLineEdit = new QLineEdit(centralwidget);
        fnameLineEdit->setObjectName("fnameLineEdit");
        fnameLineEdit->setGeometry(QRect(300, 70, 113, 22));
        mnameLabel = new QLabel(centralwidget);
        mnameLabel->setObjectName("mnameLabel");
        mnameLabel->setGeometry(QRect(40, 210, 71, 16));
        mnameLineEdit = new QLineEdit(centralwidget);
        mnameLineEdit->setObjectName("mnameLineEdit");
        mnameLineEdit->setGeometry(QRect(30, 180, 113, 22));
        birthLabel = new QLabel(centralwidget);
        birthLabel->setObjectName("birthLabel");
        birthLabel->setGeometry(QRect(200, 210, 71, 16));
        birthLineEdit = new QLineEdit(centralwidget);
        birthLineEdit->setObjectName("birthLineEdit");
        birthLineEdit->setGeometry(QRect(170, 180, 113, 22));
        phoneLabel = new QLabel(centralwidget);
        phoneLabel->setObjectName("phoneLabel");
        phoneLabel->setGeometry(QRect(340, 210, 49, 16));
        phoneLineEdit = new QLineEdit(centralwidget);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setGeometry(QRect(310, 180, 113, 22));
        facultyLabel = new QLabel(centralwidget);
        facultyLabel->setObjectName("facultyLabel");
        facultyLabel->setGeometry(QRect(50, 320, 49, 16));
        courseLabel = new QLabel(centralwidget);
        courseLabel->setObjectName("courseLabel");
        courseLabel->setGeometry(QRect(200, 320, 49, 16));
        groupLabel = new QLabel(centralwidget);
        groupLabel->setObjectName("groupLabel");
        groupLabel->setGeometry(QRect(350, 320, 49, 16));
        facultyLineEdit = new QLineEdit(centralwidget);
        facultyLineEdit->setObjectName("facultyLineEdit");
        facultyLineEdit->setGeometry(QRect(30, 280, 113, 22));
        courseLineEdit = new QLineEdit(centralwidget);
        courseLineEdit->setObjectName("courseLineEdit");
        courseLineEdit->setGeometry(QRect(170, 280, 113, 22));
        groupLineEdit = new QLineEdit(centralwidget);
        groupLineEdit->setObjectName("groupLineEdit");
        groupLineEdit->setGeometry(QRect(310, 280, 113, 22));
        createObjectButton = new QPushButton(centralwidget);
        createObjectButton->setObjectName("createObjectButton");
        createObjectButton->setGeometry(QRect(30, 390, 141, 71));
        displayObjectButton = new QPushButton(centralwidget);
        displayObjectButton->setObjectName("displayObjectButton");
        displayObjectButton->setGeometry(QRect(180, 390, 141, 71));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(350, 420, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1103, 22));
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
        idLabel->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        lnameLabel->setText(QCoreApplication::translate("MainWindow", "LastName", nullptr));
        fnameLabel->setText(QCoreApplication::translate("MainWindow", "FirstName", nullptr));
        mnameLabel->setText(QCoreApplication::translate("MainWindow", "MiddleName", nullptr));
        birthLabel->setText(QCoreApplication::translate("MainWindow", "Day of Birth", nullptr));
        phoneLabel->setText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        facultyLabel->setText(QCoreApplication::translate("MainWindow", "Faculty", nullptr));
        courseLabel->setText(QCoreApplication::translate("MainWindow", "Course", nullptr));
        groupLabel->setText(QCoreApplication::translate("MainWindow", "Group", nullptr));
        createObjectButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\276\320\261'\321\224\320\272\321\202", nullptr));
        displayObjectButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\262\320\265\321\201\321\202\320\270 \320\276\320\261'\321\224\320\272\321\202", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\205\321\226\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
