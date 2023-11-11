// paymentlistwindow.h

#ifndef PAYMENTLISTWINDOW_H
#define PAYMENTLISTWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QVector>

#include "st.payment.h"

class PaymentListWindow : public QDialog
{
    Q_OBJECT

public:
    PaymentListWindow(QWidget *parent = nullptr);
    ~PaymentListWindow();

    void setPaymentsList(const QVector<stpayment*>& payments);

private:
    QListWidget *paymentListWidget;
};

#endif
