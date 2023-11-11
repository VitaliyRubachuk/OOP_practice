#include <QVBoxLayout>
#include "paymentlistwindow.h"

PaymentListWindow::PaymentListWindow(QWidget *parent)
    : QDialog(parent),
    paymentListWidget(new QListWidget(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(paymentListWidget);
    setLayout(layout);

    setWindowTitle("Список оплат");
}

PaymentListWindow::~PaymentListWindow()
{
}

void PaymentListWindow::setPaymentsList(const QVector<stpayment*>& payments)
{
    paymentListWidget->clear();

    for (const stpayment* payment : payments) {
        QListWidgetItem* item = new QListWidgetItem(payment->toString());
        paymentListWidget->addItem(item);
    }
}
