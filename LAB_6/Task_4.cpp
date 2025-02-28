#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accNum, float bal, float rate) : Account(accNum, bal), interestRate(rate) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << ", Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accNum, float bal, float limit) : Account(accNum, bal), overdraftLimit(limit) {}

    void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << ", Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    int accNum;
    float balance, rate, limit;

    cout << "Enter Saving Account Number: ";
    cin >> accNum;
    cout << "Enter Saving Account Balance: ";
    cin >> balance;
    cout << "Enter Interest Rate: ";
    cin >> rate;
    SavingsAccount savings(accNum, balance, rate);
    savings.displayDetails();

    cout << "Enter Checking Account Number: ";
    cin >> accNum;
    cout << "Enter Checking Account Balance: ";
    cin >> balance;
    cout << "Enter Overdraft Limit: ";
    cin >> limit;
    CheckingAccount checking(accNum, balance, limit);
    checking.displayDetails();

    return 0;
}
