#include "student.h"

Student::Student(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group)
    : id(id), lname(lname), fname(fname), mname(mname), birth(birth), phone(phone), faculty(faculty), course(course), group(group)
{
}

QString Student::toString() const
{
    QString info;
    info += "ID: " + QString::number(id) + "\n";
    info += "Прізвище: " + lname + "\n";
                info += "Ім'я: " + fname + "\n";
    if (!mname.isEmpty()) {
        info += "По батькові: " + mname + "\n";
    }
    info += "Дата народження: " + birth + "\n";
            info += "Телефон: " + phone + "\n";
               info += "Факультет: " + faculty + "\n";
               info += "Курс: " + QString::number(course) + "\n";
    if (!group.isEmpty()) {
        info += "Група: " + group + "\n";
    }
    return info;
}
