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

ostream& operator<<(ostream& r, const Student& student)
{
    r << "ID: " << student.id << endl;
    r << "Прізвище: " << student.lname << endl;
    r << "Ім'я: " << student.fname << endl;
    r << "По батькові: " << student.mname << endl;
    r << "Дата народження: " << student.birth << endl;
    r << "Телефон: " << student.phone << endl;
    r << "Факультет: " << student.faculty << endl;
    r << "Курс: " << student.course << endl;
    r << "Група: " << student.group << endl;
    return r;
}

bool operator==(const Student& student1, const Student& student2) 
{
    return 
        (student1.id == student2.id &&
        student1.lname == student2.lname &&
        student1.fname == student2.fname &&
        student1.mname == student2.mname &&
        student1.birth == student2.birth &&
        student1.phone == student2.phone &&
        student1.faculty == student2.faculty &&
        student1.course == student2.course &&
        student1.group == student2.group);
}

int main()
{
    setlocale(LC_ALL, "ukr");
    Student student1, student2, student3;
    cin >> student1 >> student2 >> student3;
    cout << student1 << endl << student2 << endl << student3 << endl;

    if (student1 == student2) 
    {
        cout << "Об'єкти student1 та student2 ідентичні." << endl;
    }
    else
    {
        cout << "Об'єкти student1 та student2 різні." << endl;
    }
}