#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
public:
    Student(int id, const QString &lname, const QString &fname, const QString &mname, const QString &birth, const QString &phone, const QString &faculty, int course, const QString &group);
    QString toString() const;

    // для отримання значень приватних полів
    QString getLname() const { return lname; }
    QString getFname() const { return fname; }
    QString getMname() const { return mname; }
    QString getBirth() const { return birth; }
    QString getPhone() const { return phone; }
    QString getFaculty() const { return faculty; }
    int getCourse() const { return course; }
    QString getGroup() const { return group; }

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

#endif
