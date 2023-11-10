#include "stpaymentdialog.h"
#include <QVBoxLayout>

STPaymentDialog::STPaymentDialog(QWidget *parent)
    : QDialog(parent),
      id1LineEdit(new QLineEdit(this)),
      corps1LineEdit(new QLineEdit(this)),
      number1LineEdit(new QLineEdit(this)),
      phone1LineEdit(new QLineEdit(this)),
      faculty1LineEdit(new QLineEdit(this)),
      group1LineEdit(new QLineEdit(this)),
      createButton(new QPushButton("Create", this))
{
    setWindowTitle("Модальне вікно для оплати");
    setModal(true);

    resize(500, 300);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(createLabel1("ID:"), 0, Qt::AlignTop);
    layout->addWidget(id1LineEdit);
    layout->addWidget(createLabel1("Корпус:"), 0, Qt::AlignTop);
    layout->addWidget(corps1LineEdit);
    layout->addWidget(createLabel1("Номер квартири:"), 0, Qt::AlignTop);
    layout->addWidget(number1LineEdit);
    layout->addWidget(createLabel1("Телефон:"), 0, Qt::AlignTop);
    layout->addWidget(phone1LineEdit);
    layout->addWidget(createLabel1("Факультет:"), 0, Qt::AlignTop);
    layout->addWidget(faculty1LineEdit);
    layout->addWidget(createLabel1("Група:"), 0, Qt::AlignTop);
    layout->addWidget(group1LineEdit);
    layout->addWidget(createButton);

    connect(createButton, &QPushButton::clicked, this, &STPaymentDialog::createPayment);

}

QLabel *STPaymentDialog::createLabel1(const QString &text)
{
    QLabel *label1 = new QLabel(text, this);
    label1->setAlignment(Qt::AlignTop);
    return label1;
}

STPaymentDialog::~STPaymentDialog()
{
}

void STPaymentDialog::createPayment()
{
    int id1 = id1LineEdit->text().toInt();
    QString corps1 = corps1LineEdit->text();
    QString number1 = number1LineEdit->text();
    QString phone1 = phone1LineEdit->text();
    QString faculty1 = faculty1LineEdit->text();
    QString group1 = group1LineEdit->text();

    emit createPaymentRequested(id1, corps1, number1, phone1, faculty1, group1);
    close();
}
