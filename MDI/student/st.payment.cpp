#include "st.payment.h"

stpayment::stpayment(int id, const QString &corps, const QString &number, const QString &phone, const QString &faculty, const QString &group)
    : id(id), corps(corps), number(number), phone(phone), faculty(faculty), group(group) {}

stpayment::stpayment(const QString &number, const QString &phone, const QString &faculty, const QString &group)
    : id(0), corps(corps), number(number), phone(phone), faculty(faculty), group(group) {}

stpayment::stpayment() : id(0), corps(""), number(""), phone(""), faculty(""), group("") {}

QString stpayment::toString() const
{
    QString result = "Додаткова інформація:\n";
    result += "ID: " + QString::number(id) + "\n";
    result += "Корпус: " + corps + "\n";
    result += "Номер квартири: " + number + "\n";
    result += "Телефон: " + phone + "\n";
    result += "Факультет: " + faculty + "\n";
    result += "Група: " + group + "\n";

    return result;
}


QString stpayment::getNumber() const
{
    return number;
}

QString stpayment::getPhone() const
{
    return phone;
}

QString stpayment::getFaculty() const
{
    return faculty;
}

QString stpayment::getGroup() const
{
    return group;
}

QString stpayment::getCorps() const
{
    return corps;
}
