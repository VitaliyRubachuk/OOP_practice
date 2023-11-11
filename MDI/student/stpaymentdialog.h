#ifndef STPAYMENTDIALOG_H
#define STPAYMENTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "st.payment.h"

class STPaymentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit STPaymentDialog(QWidget *parent = nullptr);
    ~STPaymentDialog();

signals:
    void createPaymentRequested(int id1, const QString &corps1, const QString &number1, const QString &phone1, const QString &faculty1, const QString &group1);

private slots:
    void createPayment();

private:
    QLineEdit *id1LineEdit;
    QLineEdit *corps1LineEdit;
    QLineEdit *number1LineEdit;
    QLineEdit *phone1LineEdit;
    QLineEdit *faculty1LineEdit;
    QLineEdit *group1LineEdit;
    QPushButton *createButton;
    QLabel *createLabel1(const QString &text);
};

#endif
