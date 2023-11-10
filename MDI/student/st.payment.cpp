#include "st.payment.h"

stpayment::stpayment(int id1, const QString &corps1, const QString &number1, const QString &phone1, const QString &faculty1, const QString &group1)
    : id1(id1), corps1(corps1), number1(number1), phone1(phone1), faculty1(faculty1), group1(group1)
{
}

QString stpayment::toString() const
{
    QString info;
    info += "ID: " + QString::number(id1) + "\n";
    info += "Корпус: " + corps1 + "\n";
            if (!number1.isEmpty()) {
                info += "Номер квартири: " + number1 + "\n";
            }
            info += "Телефон: " + phone1 + "\n";
               info += "Факультет: " + faculty1 + "\n";
           if (!group1.isEmpty()) {
        info += "Група: " + group1 + "\n";
    }
    return info;
}
