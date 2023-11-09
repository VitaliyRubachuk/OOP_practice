#ifndef ST_PAYMENT
#define ST_PAYMENT
#include "person.h"

class stpayment : public Person
{
public:
    stpayment(int id, const QString &corps, const QString &number1, const QString &phone, const QString &faculty, const QString &group);

    QString toString() const override;

private:
    int id;
    QString corps;
    QString number1;
    QString phone;
    QString faculty;
    QString group;
};

#endif // ST_PAYMENT
