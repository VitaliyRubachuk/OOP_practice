#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    Base() : id(0), lastName(""), firstName(""), patronymic(""), accountNumber(0), electricityConsumed(0.0), amountPaid(0.0) {}
    Base(int id, const string& lastName, const string& firstName, const string& patronymic,int accountNumber, double electricityConsumed, double amountPaid)
        : id(id), lastName(lastName), firstName(firstName), patronymic(patronymic),accountNumber(accountNumber), electricityConsumed(electricityConsumed), amountPaid(amountPaid) {}
    void d()
    {
        cout << endl << "ID: " << id << endl;
        cout << "Прізвище: " << lastName << endl;
        cout << "Ім'я: " << firstName << endl;
        cout << "По батькові: " << patronymic << endl;
        cout << "Номер рахунку: " << accountNumber << endl;
        cout << "Спожито за місяць (електроенергії): " << electricityConsumed << " кВт" << endl;
        cout << "Оплачено за місяць: " << amountPaid << " грн" << endl;
    }

    void i() 
    {
        cout << "Введіть ID: ";
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
    PaymentForElectricity() = default;
};

int main() {
    setlocale(LC_ALL, "ukr");

    PaymentForElectricity payment;
    payment.i();
    payment.d();

    return 0;
}
