#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentinfowindow.h"
#include "studentlistwindow.h"
#include "paymentlistwindow.h"
#include "newobjectdialog.h"
#include "stpaymentdialog.h"
#include "studentlistwindow.h"
#include <QMessageBox>
#include <QListWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      student(nullptr),
      payment(nullptr),
      newObjectDialog(nullptr),
      paymentDialog(nullptr),
      studentListWindow(nullptr),
      paymentListWindow(nullptr)
{
    ui->setupUi(this);

    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::exit);
    connect(ui->openNewObjectDialogButton, &QPushButton::clicked, this, &MainWindow::openNewObjectDialog);
    connect(ui->openPaymentDialogButton, &QPushButton::clicked, this, &MainWindow::openPaymentDialog);
    connect(ui->FListButton, &QPushButton::clicked, this, &MainWindow::showStudentList);
    connect(ui->SListButton, &QPushButton::clicked, this, &MainWindow::showPaymentList);

    if (!newObjectDialog) {
        newObjectDialog = new NewObjectDialog(this);
        connect(newObjectDialog, &NewObjectDialog::createObjectRequested, this, &MainWindow::handleCreateObject);
    }

    if (!paymentDialog) {
        paymentDialog = new STPaymentDialog(this);
        connect(paymentDialog, &STPaymentDialog::createPaymentRequested, this, &MainWindow::handleCreatePayment);
    }

    if (!studentListWindow) {
        studentListWindow = new StudentListWindow(this);
    }

    if (!paymentListWindow) {
        paymentListWindow = new PaymentListWindow(this);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    if (student) {
        delete student;
    }
    if (payment) {
        delete payment;
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

void MainWindow::openPaymentDialog()
{
    paymentDialog->show();
}

void MainWindow::handleCreateObject(int id, const QString& lname, const QString& fname, const QString& mname, const QString& birth,const QString& phone, const QString& faculty,int course, const QString& group) {
    Student* student = new Student(id, lname, fname, mname, birth, phone, faculty, course, group);

    if (student)
    {
        delete student;
    }


    student = new Student(id, lname, fname, mname, birth, phone, faculty, course, group);
    studentsContainer.append(student);

    QMessageBox::information(this, "Інформація", "Об'єкт створено:\n" + student->toString());
}

void MainWindow::handleCreatePayment(int id1, const QString& corps1, const QString& number1, const QString& phone1, const QString& faculty1, const QString& group1)
{
    stpayment* payment = new stpayment(id1, corps1, number1, phone1, faculty1, group1);
    if (payment)
    {
        delete payment;
    }

    payment = new stpayment(id1, corps1, number1, phone1, faculty1, group1);
    paymentsContainer.append(payment);

    QMessageBox::information(this, "Інформація", "Об'єкт створено:\n" + payment->toString());
}

void MainWindow::showStudentList() {
    studentListWindow->setStudentsList(studentsContainer);
    studentListWindow->show();
}

void MainWindow::showPaymentList() {
    paymentListWindow->setPaymentsList(paymentsContainer);
    paymentListWindow->show();
}

