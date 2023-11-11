#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    student = nullptr;

    connect(ui->createObjectButton, &QPushButton::clicked, this, &MainWindow::createObject);
    connect(ui->displayObjectButton, &QPushButton::clicked, this, &MainWindow::displayObject);
    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::exit);
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

void MainWindow::createObject()
{
    QString idStr = ui->idLineEdit->text();
    QString lname = ui->lnameLineEdit->text();
    QString fname = ui->fnameLineEdit->text();
    QString mname = ui->mnameLineEdit->text();
    QString birth = ui->birthLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    QString faculty = ui->facultyLineEdit->text();
    QString courseStr = ui->courseLineEdit->text();
    QString group = ui->groupLineEdit->text();

    if (idStr.isEmpty() || lname.isEmpty() || fname.isEmpty() || birth.isEmpty() || faculty.isEmpty() || courseStr.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Заповніть усі обов'язкові поля.");
        return;
    }

    int id = idStr.toInt();
    int course = courseStr.toInt();

    if (student)
    {
        delete student;
    }

    student = new Student(id, lname, fname, mname, birth, phone, faculty, course, group);
    QMessageBox::information(this, "Інформація", "Об'єкт створено:\n" + student->toString());
}

void MainWindow::displayObject()
{
    if (student)
    {
        QMessageBox::information(this, "Інформація", "Інформація про об'єкт:\n" + student->toString());
    } else {
        QMessageBox::warning(this, "Помилка", "Об'єкт не було створено.");
    }
}
