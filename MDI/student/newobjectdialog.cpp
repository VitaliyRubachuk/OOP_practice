#include "newobjectdialog.h"
#include <QVBoxLayout>

NewObjectDialog::NewObjectDialog(QWidget *parent)
    : QDialog(parent),
    idLineEdit(new QLineEdit(this)),
    lnameLineEdit(new QLineEdit(this)),
    fnameLineEdit(new QLineEdit(this)),
    mnameLineEdit(new QLineEdit(this)),
    birthLineEdit(new QLineEdit(this)),
    phoneLineEdit(new QLineEdit(this)),
    facultyLineEdit(new QLineEdit(this)),
    courseLineEdit(new QLineEdit(this)),
    groupLineEdit(new QLineEdit(this)),
    createButton(new QPushButton("Create", this))
{
    setWindowTitle("Модальне вікно");
    setModal(true);

    resize(500, 300);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(createLabel("ID:"), 0, Qt::AlignTop);
    layout->addWidget(idLineEdit);
    layout->addWidget(createLabel("Прізвище:"), 0, Qt::AlignTop);
    layout->addWidget(lnameLineEdit);
    layout->addWidget(createLabel("Ім'я:"), 0, Qt::AlignTop);
    layout->addWidget(fnameLineEdit);
    layout->addWidget(createLabel("По батькові:"), 0, Qt::AlignTop);
    layout->addWidget(mnameLineEdit);
    layout->addWidget(createLabel("День народження:"), 0, Qt::AlignTop);
    layout->addWidget(birthLineEdit);
    layout->addWidget(createLabel("Телефон:"), 0, Qt::AlignTop);
    layout->addWidget(phoneLineEdit);
    layout->addWidget(createLabel("Факультет:"), 0, Qt::AlignTop);
    layout->addWidget(facultyLineEdit);
    layout->addWidget(createLabel("Курс:"), 0, Qt::AlignTop);
    layout->addWidget(courseLineEdit);
    layout->addWidget(createLabel("Група:"), 0, Qt::AlignTop);
    layout->addWidget(groupLineEdit);
    layout->addWidget(createButton);

    connect(createButton, &QPushButton::clicked, this, &NewObjectDialog::createObject);
}

QLabel *NewObjectDialog::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text, this);
    label->setAlignment(Qt::AlignTop);
    return label;
}

NewObjectDialog::~NewObjectDialog()
{
}

void NewObjectDialog::createObject()
{
    int id = idLineEdit->text().toInt();
    QString lname = lnameLineEdit->text();
    QString fname = fnameLineEdit->text();
    QString mname = mnameLineEdit->text();
    QString birth = birthLineEdit->text();
    QString phone = phoneLineEdit->text();
    QString faculty = facultyLineEdit->text();
    int course = courseLineEdit->text().toInt();
    QString group = groupLineEdit->text();

    emit createObjectRequested(id, lname, fname, mname, birth, phone, faculty, course, group);

    close();
}
