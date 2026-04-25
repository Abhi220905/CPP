#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    // Constructor
    BankAccount(string accNum, string name, double initialBalance) {
        accountNumber = accNum;
        ownerName = name;
        balance = initialBalance;
    }

    // Function to credit (deposit) money
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully credited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to debit (withdraw) money
    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully debited: $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    // Function to display account details
    void displayBalance() {
        cout << "--------------------------" << endl;
        cout << "Account Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    BankAccount myAccount("123456789", "Abhi K", 1000.0);

    myAccount.displayBalance();
    myAccount.credit(500.0);
    myAccount.debit(200.0);
    myAccount.displayBalance();

    return 0;
}
