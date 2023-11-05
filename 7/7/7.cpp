#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Base
{
public:
    virtual void display() = 0;
};

class S1 : public Base
{
public:
    void display() override 
    {
        cout << "Об'єкт похідного класу 1" << endl;
    }
};

class S2 : public Base
{
public:
    void display() override
    {
        cout << "Об'єкт похідного класу 2" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ukr");
    vector<int> add(10);
    vector<int> add2(10);

    for (int i = 0, dd = 1, dd2 = 2; i < 10; i++, dd += 2, dd2 += 2)
    {
        add[i] = dd;
        add2[i] = dd2;
    }

    vector<int> merged(20);
    sort(add.begin(), add.end());
    sort(add2.begin(), add2.end());
    merge(add.begin(), add.end(), add2.begin(), add2.end(), merged.begin());

    cout << "Непарні числа: ";
    for (int num : add) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Парні числа: ";
    for (int num : add2)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Об'єднані числа: ";
    for (int num : merged) 
    {
        cout << num << " ";
    }
    cout << endl;

    vector<Base*> O;
    while (true) 
    {
        cout << endl << "Меню:" << endl;
        cout << "1. Додати об'єкт класу S1" << endl;
        cout << "2. Додати об'єкт класу S2" << endl;
        cout << "3. Вивести об'єкти" << endl;
        cout << "4. Вийти" << endl;

        int k;
        cin >> k;
        switch (k)
        {
        case 1:
            O.push_back(new S1());
            cout << "Об'єкт класу S1 додано." << endl;
            break;
        case 2:
            O.push_back(new S2());
            cout << "Об'єкт класу S2 додано." << endl;
            break;
        case 3:
            cout << "Виведення об'єктів:" << endl;
            for (Base* o : O)
            {
                o->display();
            }
            break;
        case 4:
            for (Base* o : O) 
            {
                delete o;
            }
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }
    return 0;
}

