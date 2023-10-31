#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    Base() : id(0), lastName(""), firstName(""), patronymic(""), accountNumber(0), electricityConsumed(0.0), amountPaid(0.0) {}
    Base(int id, const string& lastName, const string& firstName, const string& patronymic, int accountNumber, double electricityConsumed, double amountPaid)
        : id(id), lastName(lastName), firstName(firstName), patronymic(patronymic), accountNumber(accountNumber), electricityConsumed(electricityConsumed), amountPaid(amountPaid) {}

    virtual void dI() const = 0;

    void i()
    {
        cout << endl << "Введіть ID: ";
        cin >> id;
        cout << "Введіть прізвище: ";
        cin >> lastName;
        cout << "Введіть ім'я: ";
        cin >> firstName;
        cout << "Введіть по батькові: ";
        cin >> patronymic;
        cout << "Введіть номер рахунку: ";
        cin >> accountNumber;
        cout << "Введіть спожито за місяць (електроенергії): ";
        cin >> electricityConsumed;
        cout << "Введіть оплачено за місяць: ";
        cin >> amountPaid;
    }

protected:
    int id;
    string lastName;
    string firstName;
    string patronymic;
    int accountNumber;
    double electricityConsumed;
    double amountPaid;
};


class PaymentForElectricity : public Base
{
public:

    void dI() const override
    {
        cout << endl << "ID: " << id << endl;
        cout << "Прізвище: " << lastName << endl;
        cout << "Ім'я: " << firstName << endl;
        cout << "По батькові: " << patronymic << endl;
        cout << "Номер рахунку: " << accountNumber << endl;
        cout << "Спожито за місяць (електроенергії): " << electricityConsumed << " кВт" << endl;
        cout << "Оплачено за місяць: " << amountPaid << " грн" << endl;
    }
};

void dMenu()
{
    cout << endl << "Меню:" << endl;
    cout << "1. Створити об'єкт PaymentForElectricity" << endl;
    cout << "2. Вийти" << endl;
    cout << "Виберіть опцію: " ;
}

int main()
{
    setlocale(LC_ALL, "ukr");

    int c;
    PaymentForElectricity* A[5] = { nullptr };

    for (int i = 0; i < 5; i++)
    {
        dMenu();
        cin >> c;

        switch (c)
        {
        case 1:
            if (A[i] != nullptr)
            {
                delete A[i];
            }
            A[i] = new PaymentForElectricity();
            A[i]->i();
            break;
        case 2:
            cout << "//" << endl;
            for (int j = 0; j < 5; j++)
            {
                if (A[j] != nullptr)
                {
                    A[j]->dI(); 
                    delete A[j];
                }
            }
            return 0;
        default:
            cout << "Невірний вибір" << endl;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (A[i] != nullptr)
        {
            A[i]->dI(); 
        }
    }

    return 0;
}

