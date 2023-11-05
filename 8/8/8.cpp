#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>

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
    list<int> add;
    list<int> add2;
    list<int> merget;
    for (int i = 1; i <= 10; i += 2)
    {
        add.push_back(i);
    }
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 10; i++) 
    {
        int R = 2 * (rand() % 10 + 1);  
        add2.push_back(R);
    }
    add.sort();
    add2.sort();
    merge(add.begin(), add.end(), add2.begin(), add2.end(), back_inserter(merget));

    cout << "Непарні числа: ";
    for (const int& num : add) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Парні числа: ";
    for (const int& num : add2)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Об'єднані числа: ";
    for (const int& num : merget) 
    {
        cout << num << " ";
    }
    cout << endl;
    map<int, Base*> Q;
    int nex = 1;
    while (true) 
    {
        cout << endl << "Меню:" << endl;
        cout << "1. Додати об'єкт класу S1" << endl;
        cout << "2. Додати об'єкт класу S2" << endl;
        cout << "3. Вивести об'єкт за ID" << endl;
        cout << "4. Вийти" << endl;
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
            Q[nex] = new S1();
            cout <<endl << "Об'єкт класу S1 додано з ID = " << nex << endl;
            nex++;
            break;
        case 2:
            Q[nex] = new S2();
            cout << endl << "Об'єкт класу S2 додано з ID = " << nex << endl;
            nex++;
            break;
        case 3:
            int iD;
            cout << endl << "Введіть ID: ";
            cin >> iD;
            if (Q.find(iD) != Q.end()) 
            {
                Q[iD]->display();
            }
            else {
                cout << "ID не знайдено." << endl;
            }
            break;
        case 4:
            for (const auto& pair : Q) 
            {
                delete pair.second;
            }
            return 0;
        default:
            cout << "Невірний вибір." << endl;
        }
    }
    return 0;
}
