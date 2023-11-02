#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string lname;
    string fname;
    string mname;
    string birth;
    string phone;
    string faculty;
    int course;
    string group;

public:
    // Додана реалізація конструктора за замовчуванням
    Student() : id(0), lname(""), fname(""), mname(""), birth(""), phone(""), faculty(""), course(0), group("") {
        // Встановлення значень за замовчуванням для всіх полів
    }

    Student(int, string, string, string, string, string, string, int, string);
    Student(const Student&);
    ~Student();

    friend istream& operator>>(istream& W, Student& student);
    friend ostream& operator<<(ostream& r, const Student& student);
    friend bool operator==(const Student& student1, const Student& student2);
};
