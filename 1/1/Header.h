#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student 
{
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
    Student();
    Student(int, string, string, string, string, string, string, int, string);
    Student(const Student&);
    ~Student();
    friend istream& operator>>(istream& W, Student& student);
    friend ostream& operator<<(ostream& r, const Student& student);
    friend bool operator==(const Student& student1, const Student& student2);
};