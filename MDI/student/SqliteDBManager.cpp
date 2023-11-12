#include "sqlitedbmanager.h"
#include "student.h"
#include "st.payment.h"
#include <QSqlError>
SqliteDBManager::SqliteDBManager()
{
}

SqliteDBManager::~SqliteDBManager()
{
    closeDataBase();
}

void SqliteDBManager::connectToDataBase()
{
    if (!openDataBase())
    {
        qDebug() << "Не під'єднує.";
    } else {
        qDebug() << "З'єднано.";
        createTables();
    }
}

void SqliteDBManager::closeDataBase()
{
    db.close();
}

QSqlDatabase SqliteDBManager::getDB()
{
    return db;
}

bool SqliteDBManager::createTables()
{
    QSqlQuery query(db);


    QString createStudentsTableQuery =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "lname TEXT NOT NULL,"
        "fname TEXT NOT NULL,"
        "mname TEXT,"
        "birth TEXT NOT NULL,"
        "phone TEXT NOT NULL,"
        "faculty TEXT NOT NULL,"
        "course INTEGER NOT NULL,"
        "group_name TEXT NOT NULL"
        ");";

    if (!query.exec(createStudentsTableQuery))
    {
        qDebug() << "Таблиця не створена:" << query.lastError();
        return false;
    }

    QString createPaymentsTableQuery =
        "CREATE TABLE IF NOT EXISTS payments ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "corps TEXT NOT NULL,"
        "number TEXT,"
        "phone TEXT NOT NULL,"
        "faculty TEXT NOT NULL,"
        "group_name TEXT NOT NULL"
        ");";

    if (!query.exec(createPaymentsTableQuery))
    {
        qDebug() << "Таблиця не створена:" << query.lastError();
        return false;
    }

    return true;
}

bool SqliteDBManager::insertIntoTable(const Student &student)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO students (lname, fname, mname, birth, phone, faculty, course, group_name)" "VALUES (:lname, :fname, :mname, :birth, :phone, :faculty, :course, :group_name);");

    //для отримання значень приватних полів
    query.bindValue(":lname", student.getLname());
    query.bindValue(":fname", student.getFname());
    query.bindValue(":mname", student.getMname());
    query.bindValue(":birth", student.getBirth());
    query.bindValue(":phone", student.getPhone());
    query.bindValue(":faculty", student.getFaculty());
    query.bindValue(":course", student.getCourse());
    query.bindValue(":group_name", student.getGroup());

    if (!query.exec())
    {
        qDebug() << "Вставка провалилась:" << query.lastError();
        return false;
    }

    return true;
}

bool SqliteDBManager::clearTables()
{
    QSqlQuery query(db);

    if (!query.exec("DELETE FROM students"))
    {
        qDebug() << "Помилка видалення записів з таблиці students:" << query.lastError();
        return false;
    }

    if (!query.exec("DELETE FROM payments"))
    {
        qDebug() << "Помилка видалення записів з таблиці payments:" << query.lastError();
        return false;
    }

    if (!query.exec("DELETE FROM sqlite_sequence WHERE name='students' OR name='payments'"))
    {
        qDebug() << "Помилка скидання значення sqlite_sequence:" << query.lastError();
        return false;
    }

    return true;
}


bool SqliteDBManager::insertIntoTable(const stpayment &payment)
{
    QSqlQuery query;
    query.prepare("INSERT INTO payments (corps, number, phone, faculty, group_name) VALUES (:corps, :number, :phone, :faculty, :group_name)");
    query.bindValue(":corps", payment.getCorps());
    query.bindValue(":number", payment.getNumber());
    query.bindValue(":phone", payment.getPhone());
    query.bindValue(":faculty", payment.getFaculty());
    query.bindValue(":group_name", payment.getGroup());

    if (!query.exec())
    {
        qDebug() << "Вставка провалилась:" << query.lastError();
            return false;
    }

    return true;
}


bool SqliteDBManager::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mydatabase.db");

    if (!db.open())
    {
        qDebug() << "База даних не відкривається:" << db.lastError();
        return false;
    }

    return true;
}

QVector<Student*> SqliteDBManager::getStudents()
{
    QVector<Student*> students;
    QSqlQuery query(db);

    if (query.exec("SELECT * FROM students"))
    {
        while (query.next())
        {
            int id = query.value("id").toInt();
            QString lname = query.value("lname").toString();
            QString fname = query.value("fname").toString();
            QString mname = query.value("mname").toString();
            QString birth = query.value("birth").toString();
            QString phone = query.value("phone").toString();
            QString faculty = query.value("faculty").toString();
            int course = query.value("course").toInt();
            QString group = query.value("group_name").toString();

            Student *student = new Student(id, lname, fname, mname, birth, phone, faculty, course, group);
            students.append(student);
        }
    } else
    {
        qDebug() << "Невдале витягнення інформації:" << query.lastError();
    }

    return students;
}

QVector<stpayment*> SqliteDBManager::getPayments()
{
    QVector<stpayment*> payments;
    QSqlQuery query(db);

    if (query.exec("SELECT * FROM payments"))
    {
        while (query.next())
        {
            int id = query.value("id").toInt();
            QString number = query.value("number").toString();
            QString phone = query.value("phone").toString();
            QString faculty = query.value("faculty").toString();
            QString group = query.value("group_name").toString();

            stpayment *payment = new stpayment(id, "", number, phone, faculty, group);
            payments.append(payment);
        }
    } else
    {
        qDebug() << "База даних не відкривається:" << query.lastError();
    }

    return payments;
}
