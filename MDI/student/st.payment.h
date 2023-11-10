
#ifndef ST_PAYMENT_H
#define ST_PAYMENT_H
#include "person.h"

class stpayment : public Person
{
public:
    stpayment(int id1, const QString &corps1, const QString &number1, const QString &phone1, const QString &faculty1, const QString &group1);

    QString toString() const override;

private:
    int id1;
    QString corps1;
    QString number1;
    QString phone1;
    QString faculty1;
    QString group1;
};

#endif // ST_PAYMENT_H
