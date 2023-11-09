// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "newobjectdialog.h"
#include "stpaymentdialog.h"

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
    void handleCreatePayment(int id, const QString &corps, const QString &number1, const QString &phone, const QString &faculty, const QString &group);

private:
    Ui::MainWindow *ui;
    Student *student;
    NewObjectDialog *newObjectDialog;  // Додайте цей рядок
    STPaymentDialog *paymentDialog;   // І, можливо, цей рядок, якщо використовуєте STPaymentDialog
};

#endif // MAINWINDOW_H
