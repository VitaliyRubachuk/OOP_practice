#ifndef STPAYMENT_H
#define STPAYMENT_H

#include <QString>

class stpayment
{
public:
    stpayment(int id, const QString &corps, const QString &number, const QString &phone, const QString &faculty, const QString &group);
    stpayment(const QString &number, const QString &phone, const QString &faculty, const QString &group);
    stpayment();

    QString toString() const;
    QString getCorps() const;
    QString getNumber() const;
    QString getPhone() const;
    QString getFaculty() const;
    QString getGroup() const;

private:
    int id;
    QString corps;
    QString number;
    QString phone;
    QString faculty;
    QString group;
};

#endif
