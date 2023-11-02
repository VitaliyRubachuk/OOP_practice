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
    Student() : id(0), lname(""), fname(""), mname(""), birth(""), phone(""), faculty(""), course(0), group("") {}
    Student(int _id, string _lname, string _fname) : id(_id), lname(_lname), fname(_fname), mname(""), birth(""), phone(""), faculty(""), course(0), group("") {}
    Student(const Student&);
    ~Student();

    friend istream& operator>>(istream& W, Student& student)
    {
        cout << endl << "Введіть дані студента:" << endl;
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

    friend ostream& operator<<(ostream& r, const Student& student)
    {
        r << endl << "ID: " << student.id << endl;
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


    friend bool operator==(const Student& student1, const Student& student2)
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

};

template <class T>
class Vector
{
public:
    Vector() : size(0), capacity(10)
    {
        array = new T[capacity];
    }

    int S() const
    {
        return size;
    }

    int C() const
    {
        return capacity;
    }

    void P(const T& element) 
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* new_array = new T[capacity];
            for (int i = 0; i < size; ++i)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }

        array[size++] = element;
    }

    void Z() 
    {
        if (size > 0) 
        {
            --size;
        }
        else {
            throw out_of_range("Пусто");
        }
    }

    T at(int index) const
    {
        if (index < 0 || index >= size) 
        {
            throw out_of_range("--");
        }
        return array[index];
    }

    T operator[](int index) const 
    {
        return at(index);
    }

    ~Vector()
    {
        delete[] array;
    }

private:
    T* array;
    int size;
    int capacity;
};

int main() 
{
    setlocale(LC_ALL, "ukr");
    Vector<Student*> vector;
    Student* student1 = new Student();
    cin >> *student1;
    Student* student2 = new Student();
    cin >> *student2;
    vector.P(student1);
    vector.P(student2);


    for (int i = 0; i < vector.S(); ++i) 
    {
        cout << endl << "Студент " << i + 1 << ":" << endl;
        cout << *vector[i] << endl;
    }


    vector.Z();
    vector.Z();

    return 0;
}


