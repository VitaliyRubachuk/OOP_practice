#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "student.h"
#include "stpaymentdialog.h"
#include "newobjectdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      student(nullptr),
      payment(nullptr),
      newObjectDialog(nullptr),
      paymentDialog(nullptr)
{
    ui->setupUi(this);

    connect(ui->exit, &QPushButton::clicked, this, &MainWindow::exit);
    connect(ui->openNewObjectDialogButton, &QPushButton::clicked, this, &MainWindow::openNewObjectDialog);
    connect(ui->openPaymentDialogButton, &QPushButton::clicked, this, &MainWindow::openPaymentDialog);

    if (!newObjectDialog) {
        newObjectDialog = new NewObjectDialog(this);
        connect(newObjectDialog, &NewObjectDialog::createObjectRequested, this, &MainWindow::handleCreateObject);
    }

    if (!paymentDialog) {
        paymentDialog = new STPaymentDialog(this);
        connect(paymentDialog, &STPaymentDialog::createPaymentRequested, this, &MainWindow::handleCreatePayment);
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

void MainWindow::handleCreateObject(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group)
{
    if (student) {
        delete student;
    }

    student = new Student(id, lname, fname, mname, birth, phone, faculty, course, group);

    QMessageBox::information(this, "Інформація", "Об'єкт створено:\n" + student->toString());
}

void MainWindow::handleCreatePayment(int id1, const QString &corps1, const QString &number1, const QString &phone1, const QString &faculty1, const QString &group1)
{
    if (payment)
    {
        delete payment;
    }

    payment = new stpayment(id1, corps1, number1, phone1, faculty1, group1);

    QMessageBox::information(this, "Інформація", "Об'єкт створено:\n" + payment->toString());
}
