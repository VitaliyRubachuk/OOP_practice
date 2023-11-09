#include "stpaymentdialog.h"
#include <QVBoxLayout>

STPaymentDialog::STPaymentDialog(QWidget *parent)
    : QDialog(parent),
      idLineEdit(new QLineEdit(this)),
      corpsLineEdit(new QLineEdit(this)),
      number1LineEdit(new QLineEdit(this)),
      phoneLineEdit(new QLineEdit(this)),
      facultyLineEdit(new QLineEdit(this)),
      groupLineEdit(new QLineEdit(this)),
      createButton(new QPushButton("Create", this))
{
    setWindowTitle("Модальне вікно для оплати");
    setModal(true);

    resize(500, 300);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(createLabel("ID:"), 0, Qt::AlignTop);
    layout->addWidget(idLineEdit);
    layout->addWidget(createLabel("Корпус:"), 0, Qt::AlignTop);
    layout->addWidget(corpsLineEdit);
    layout->addWidget(createLabel("Номер квартири:"), 0, Qt::AlignTop);
    layout->addWidget(number1LineEdit);
    layout->addWidget(createLabel("Телефон:"), 0, Qt::AlignTop);
    layout->addWidget(phoneLineEdit);
    layout->addWidget(createLabel("Факультет:"), 0, Qt::AlignTop);
    layout->addWidget(facultyLineEdit);
    layout->addWidget(createLabel("Група:"), 0, Qt::AlignTop);
    layout->addWidget(groupLineEdit);
    layout->addWidget(createButton);

    connect(createButton, &QPushButton::clicked, this, &STPaymentDialog::createPayment);
}

QLabel *STPaymentDialog::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text, this);
    label->setAlignment(Qt::AlignTop);
    return label;
}

STPaymentDialog::~STPaymentDialog()
{
}

void STPaymentDialog::createPayment()
{
    int id = idLineEdit->text().toInt();
    QString corps = corpsLineEdit->text();
    QString number1 = number1LineEdit->text();
    QString phone = phoneLineEdit->text();
    QString faculty = facultyLineEdit->text();
    QString group = groupLineEdit->text();

    emit createPaymentRequested(id, corps, number1, phone, faculty, group);
    close();
}
