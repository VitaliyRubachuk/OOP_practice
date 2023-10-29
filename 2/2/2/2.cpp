#include <iostream>
#include <string>

using namespace std;

class PaymentForElectricity
{
public:
    PaymentForElectricity() : id(0), lastName(""), firstName(""), patronymic(""), accountNumber(0), electricityConsumed(0.0), amountPaid(0.0) {}
    PaymentForElectricity(int id, const string& lastName, const string& firstName, const string& patronymic, int accountNumber, double electricityConsumed, double amountPaid)
        : id(id), lastName(lastName), firstName(firstName), patronymic(patronymic), accountNumber(accountNumber), electricityConsumed(electricityConsumed), amountPaid(amountPaid) {}
    void d()
    {
        cout << "ID: " << id << endl;
        cout << "Прізвище: " << lastName << endl;
        cout << "Ім'я: " << firstName << endl;
        cout << "По батькові: " << patronymic << endl;
        cout << "Номер рахунку: " << accountNumber << endl;
        cout << "Спожито за місяць (електроенергії): " << electricityConsumed << " кВт" << endl;
        cout << "Оплачено за місяць: " << amountPaid << " грн" << endl;
    }
    void e()
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
private:
    int id;
    string lastName;
    string firstName;
    string patronymic;
    int accountNumber;
    double electricityConsumed;
    double amountPaid;
};

int main()
{
    setlocale(LC_ALL, "ukr");
    PaymentForElectricity payment;
    payment.e();

    payment.d();

    return 0;
}