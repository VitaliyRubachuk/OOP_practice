#include "Header.h"
using namespace std;

Student::Student()
{
    id = 0;
    lname = "";
    fname = "";
    mname = "";
    birth = "";
    phone = "";
    faculty = "";
    course = 0;
    group = "";
}

Student::Student(int id, string lname, string fname, string mname, string birth, string phone, string faculty, int course, string group)
{
    this->id = id;
    this->lname = lname;
    this->fname = fname;
    this->mname = mname;
    this->birth = birth;
    this->phone = phone;
    this->faculty = faculty;
    this->course = course;
    this->group = group;
}

Student::Student(const Student& other)
{
    this->id = other.id;
    this->lname = other.lname;
    this->fname = other.fname;
    this->mname = other.mname;
    this->birth = other.birth;
    this->phone = other.phone;
    this->faculty = other.faculty;
    this->course = other.course;
    this->group = other.group;
}

Student::~Student()
{
}

istream& operator>>(istream& W, Student& student)
{
    cout << "Введіть дані студента:" << endl;
    cout << "ID: ";
    W >> student.id;
    cout << "Прізвище: ";
    W >> student.lname;
    cout << "Ім'я: ";
    W >> student.fname;
    cout << "По батькові: ";
    W >> student.mname;
    cout << "Дата народження: ";
    W >> student.birth;
    cout << "Телефон: ";
    W >> student.phone;
    cout << "Факультет: ";
    W >> student.faculty;
    cout << "Курс: ";
    W >> student.course;
    cout << "Група: ";
    W >> student.group;
    return W;
}


int main()
{
    setlocale(LC_ALL, "ukr");
    Student object1;
    cin >> object1;

}