#include <iostream>
#include <string>
using namespace std;

class Manager;

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initialBalance) 
        : accountNumber(accNum), balance(initialBalance) {}

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount, Manager& manager);

    void displayInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Manager {
public:
    void deposit(Account& account, double amount) {
        if (amount > 0) {
            account.balance += amount;
            cout << "Deposited $" << amount << " to account " << account.accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(Account& account, double amount) {
        if (amount > 0 && amount <= account.balance) {
            account.balance -= amount;
            cout << "Withdrew $" << amount << " from account " << account.accountNumber << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }

    void displayAccountInfo(const Account& account) {
        cout << "\nAccount Details:" << endl;
        account.displayInfo();
        cout << "-----------------" << endl;
    }
};

void transferFunds(Account& from, Account& to, double amount, Manager& manager) {
    if (amount > 0 && from.balance >= amount) {
        manager.withdraw(from, amount);
        manager.deposit(to, amount);
        cout << "Transferred $" << amount << " from account " << from.accountNumber 
             << " to account " << to.accountNumber << endl;
    } else {
        cout << "Transfer failed: Invalid amount or insufficient funds!" << endl;
    }
}

int main() {
    Account acc1("ACC123", 1000.0);
    Account acc2("ACC456", 500.0);
    Manager bankManager;

    bankManager.displayAccountInfo(acc1);
    bankManager.displayAccountInfo(acc2);

    bankManager.deposit(acc1, 200.0);
    bankManager.withdraw(acc2, 100.0);

    transferFunds(acc1, acc2, 300.0, bankManager);

    bankManager.displayAccountInfo(acc1);
    bankManager.displayAccountInfo(acc2);

    return 0;
}
