#include "st.payment.h"

stpayment::stpayment(int id, const QString &corps, const QString &number1, const QString &phone, const QString &faculty, const QString &group)
    : id(id), corps(corps), number1(number1), phone(phone), faculty(faculty), group(group)
{
}

QString stpayment::toString() const
{
    QString info;
    info += "ID: " + QString::number(id) + "\n";
    info += "Корпус: " + corps + "\n";
    info += "Номер квартири: " + number1 + "\n";
    info += "Телефон: " + phone + "\n";
    info += "Факультет: " + faculty + "\n";
    info += "Група: " + group + "\n";
    return info;
}
