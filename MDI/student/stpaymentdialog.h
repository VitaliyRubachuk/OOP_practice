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
    void createPaymentRequested(int id, const QString &corps, const QString &number1, const QString &phone, const QString &faculty, const QString &group);

private slots:
    void createPayment();

private:
    QLineEdit *idLineEdit;
    QLineEdit *corpsLineEdit;
    QLineEdit *number1LineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *facultyLineEdit;
    QLineEdit *groupLineEdit;
    QPushButton *createButton;
    QLabel *createLabel(const QString &text);
};

#endif // STPAYMENTDIALOG_H
