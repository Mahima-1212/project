#include <iostream>
#include <string>
using namespace std;

// Base class
class Account {
protected:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor
    Account(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    // Display account details
    void display() {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class for Savings Account
class SavingsAccount : public Account {
public:
    SavingsAccount(string name, int accNo, double initialBalance)
        : Account(name, accNo, initialBalance) {}

    // Example of encapsulation: interest calculation
    void addInterest(double rate) {
        double interest = balance * rate / 100;
        balance += interest;
        cout << "Interest added: " << interest << endl;
    }
};

int main() {
    string name;
    int accNo;
    double initialBalance;

    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    // Create a Savings Account object
    SavingsAccount acc(name, accNo, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n--- Bank Menu ---" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Display Account Details" << endl;
        cout << "4. Add Interest" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            break;
        case 3:
            acc.display();
            break;
        case 4:
            cout << "Enter interest rate (%): ";
            cin >> amount;
            acc.addInterest(amount);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
