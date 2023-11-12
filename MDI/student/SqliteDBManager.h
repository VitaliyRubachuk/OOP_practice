#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include "student.h"
#include "st.payment.h"

class SqliteDBManager
{
public:
    SqliteDBManager();
    ~SqliteDBManager();

    void connectToDataBase();
    void closeDataBase();
    QSqlDatabase getDB();
    bool createTables();
    bool clearTables();
    bool insertIntoTable(const Student &student);
    bool insertIntoTable(const stpayment &payment);
    QVector<Student*> getStudents();
    QVector<stpayment*> getPayments();

private:
    bool openDataBase();
    QSqlDatabase db;
};

#endif
