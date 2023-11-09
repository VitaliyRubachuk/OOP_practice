#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    student(nullptr),
    newObjectDialog(nullptr)
{
    ui->setupUi(this);

    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::exit);
    connect(ui->openNewObjectDialogButton, &QPushButton::clicked, this, &MainWindow::openNewObjectDialog);

    if (!newObjectDialog) {
        newObjectDialog = new NewObjectDialog(this);
        connect(newObjectDialog, &NewObjectDialog::createObjectRequested, this, &MainWindow::handleCreateObject);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if (student) {
        delete student;
    }
}

void MainWindow::exit()
{
    QApplication::quit();
}

void MainWindow::openNewObjectDialog()
{
    newObjectDialog->show();
}

void MainWindow::handleCreateObject(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group)
{
    if (student) {
        delete student;
    }

    student = new Student(id, lname, fname, mname, birth, phone, faculty, course, group);

    QMessageBox::information(this, "Інформація", "Об'єкт створено:\n" + student->toString());
}
