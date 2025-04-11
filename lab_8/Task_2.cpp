#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << endl;
        cout << "Balance: Rs. " << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        acc.balance += amount;
        cout << "Deposited Rs. " << amount << " into Account " << acc.accountNumber << endl;
    }

    void withdraw(Account& acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrawn Rs. " << amount << " from Account " << acc.accountNumber << endl;
        } else {
            cout << "Insufficient balance in Account " << acc.accountNumber << endl;
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred Rs. " << amount << " from Account " << from.accountNumber 
             << " to Account " << to.accountNumber << endl;
    } else {
        cout << "Transfer failed. Insufficient balance in Account " << from.accountNumber << endl;
    }
}

int main() {
    Account acc1("PK123456", 5000.0);
    Account acc2("PK789012", 3000.0);

    Manager bankManager;

    cout << "Initial Account Details:" << endl;
    bankManager.displayAccount(acc1);
    bankManager.displayAccount(acc2);

    bankManager.deposit(acc1, 2000.0);
    bankManager.withdraw(acc2, 1000.0);

    transferFunds(acc1, acc2, 1500.0);

    cout << "\nUpdated Account Details:" << endl;
    bankManager.displayAccount(acc1);
    bankManager.displayAccount(acc2);

    return 0;
}
