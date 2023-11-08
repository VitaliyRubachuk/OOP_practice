#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group);
    QString toString() const;

private:
    int id;
    QString lname;
    QString fname;
    QString mname;
    QString birth;
    QString phone;
    QString faculty;
    int course;
    QString group;
};

#endif // STUDENT_H
