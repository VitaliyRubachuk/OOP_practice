#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sqlitedbmanager.h"
#include <QMainWindow>
#include "student.h"
#include "st.payment.h"
#include "newobjectdialog.h"
#include "stpaymentdialog.h"
#include "studentlistwindow.h"
#include "paymentlistwindow.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>

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
    static void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void onClearTablesClicked();
    void exit();
    void openNewObjectDialog();
    void openPaymentDialog();
    void handleCreateObject(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group);
    void handleCreatePayment(int id1, const QString &corps1, const QString &number1, const QString &phone1, const QString &faculty1, const QString &group1);
    void showStudentList();
    void showPaymentList();

private:
    Ui::MainWindow *ui;
    SqliteDBManager dbManager;
    QSqlTableModel *model;
    Student *student;
    stpayment *payment;
    NewObjectDialog *newObjectDialog;
    STPaymentDialog *paymentDialog;
    StudentListWindow *studentListWindow;
    PaymentListWindow *paymentListWindow;
};

#endif
