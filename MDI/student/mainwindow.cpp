#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studentinfowindow.h"
#include "studentlistwindow.h"
#include "paymentlistwindow.h"
#include "newobjectdialog.h"
#include "stpaymentdialog.h"
#include "sqlitedbmanager.h"
#include <QMessageBox>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      model(nullptr),
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
    connect(ui->clearTablesButton, &QPushButton::clicked, this, &MainWindow::onClearTablesClicked);


    model = new QSqlTableModel(this);
    model->setTable("students");
    model->select();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete student;
    delete payment;
    delete newObjectDialog;
    delete paymentDialog;
    delete studentListWindow;
    delete paymentListWindow;
}

void MainWindow::exit()
{
    QApplication::quit();
}

void MainWindow::onClearTablesClicked()
{
    bool success = dbManager.clearTables();
    if (success)
    {
        qDebug() << "Таблиця очищена!";
    } else {
        qDebug() << "Не вдалось очистити таблицю!";
    }
}


void MainWindow::openNewObjectDialog()
{
    if (!newObjectDialog)
    {
        newObjectDialog = new NewObjectDialog(this);
        connect(newObjectDialog, &NewObjectDialog::createObjectRequested, this, &MainWindow::handleCreateObject);
    }
    newObjectDialog->show();
}

void MainWindow::openPaymentDialog()
{
    if (!paymentDialog)
    {
        paymentDialog = new STPaymentDialog(this);
        connect(paymentDialog, &STPaymentDialog::createPaymentRequested, this, &MainWindow::handleCreatePayment);
    }
    paymentDialog->show();
}

void MainWindow::handleCreateObject(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), id);
    model->setData(model->index(0, 1), lname);
    model->setData(model->index(0, 2), fname);
    model->setData(model->index(0, 3), mname);
    model->setData(model->index(0, 4), birth);
    model->setData(model->index(0, 5), phone);
    model->setData(model->index(0, 6), faculty);
    model->setData(model->index(0, 7), course);
    model->setData(model->index(0, 8), group);

    Student student(id, lname, fname, mname, birth, phone, faculty, course, group);

    dbManager.connectToDataBase();
    dbManager.createTables();
    dbManager.insertIntoTable(student);

    QMessageBox::information(this, "Інформація", "Об'єкт створено:\n" + student.toString());
}

void MainWindow::handleCreatePayment(int id1, const QString &corps1, const QString &number1, const QString &phone1, const QString &faculty1, const QString &group1)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), id1);
    model->setData(model->index(0, 1), corps1);
    model->setData(model->index(0, 2), number1);
    model->setData(model->index(0, 3), phone1);
    model->setData(model->index(0, 4), faculty1);
    model->setData(model->index(0, 5), group1);

    stpayment payment(id1, corps1, number1, phone1, faculty1, group1);

    dbManager.connectToDataBase();
    dbManager.createTables();

    if (dbManager.insertIntoTable(payment))
    {
        QMessageBox::information(this, "Інформація", "Об'єкт створено і збережено в базі:\n" + payment.toString());
    } else {
        QMessageBox::warning(this, "Помилка", "Не вдалося зберегти об'єкт в базі.");
    }
}


void MainWindow::showStudentList()
{
    if (!studentListWindow)
    {
        studentListWindow = new StudentListWindow(this);
        connect(studentListWindow, &QDialog::finished, this, [this]
                {
            delete studentListWindow;
            studentListWindow = nullptr;
        });
    }

    dbManager.connectToDataBase();
    QVector<Student *> students = dbManager.getStudents();

    studentListWindow->setStudentsList(students);
    studentListWindow->show();
}

void MainWindow::showPaymentList()
{
    if (!paymentListWindow) {
        paymentListWindow = new PaymentListWindow(this);
        connect(paymentListWindow, &QDialog::finished, this, [this]
                {
            delete paymentListWindow;
            paymentListWindow = nullptr;
        });
    }

    dbManager.connectToDataBase();
    QVector<stpayment *> payments = dbManager.getPayments();

    paymentListWindow->setPaymentsList(payments);
    paymentListWindow->show();
}



