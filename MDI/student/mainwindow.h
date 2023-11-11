#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "st.payment.h"
#include "newobjectdialog.h"
#include "stpaymentdialog.h"
#include "studentlistwindow.h"
#include "paymentlistwindow.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void exit();
    void openNewObjectDialog();
    void openPaymentDialog();
    void handleCreateObject(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group);
    void handleCreatePayment(int id1, const QString &corps1, const QString &number1, const QString &phone1, const QString &faculty1, const QString &group1);
    void showStudentList();
    void showPaymentList();

private:
    Ui::MainWindow *ui;
    Student *student;
    stpayment *payment;
    NewObjectDialog *newObjectDialog;
    STPaymentDialog *paymentDialog;
    StudentListWindow *studentListWindow;
    PaymentListWindow *paymentListWindow;
    QVector<Student*> studentsContainer;
    QVector<stpayment*> paymentsContainer;
};

#endif
