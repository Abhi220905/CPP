#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accNo;
    string name;
    double balance;

public:
    void setData(int a, string n, double b) {
        accNo = a;
        name = n;
        balance = b;
    }

    virtual void deposit(double amt) {
        balance += amt;
    }

    virtual void withdraw(double amt) {
        if (amt <= balance) balance -= amt;
    }

    virtual void display() {
        cout << accNo << " " << name << " " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
    double rate;

public:
    void setSaving(int a, string n, double b, double r) {
        setData(a, n, b);
        rate = r;
    }

    void interest() {
        cout << balance * rate / 100 << endl;
    }
};

class CheckingAccount : public BankAccount {
    double limit;

public:
    void setCheck(int a, string n, double b, double l) {
        setData(a, n, b);
        limit = l;
    }

    void withdraw(double amt) {
        if (amt <= balance + limit) balance -= amt;
    }
};

int main() {
    SavingsAccount s;
    CheckingAccount c;
    int ch;

    do {
        cout << "1.Savings 2.Checking 3.Exit\n";
        cin >> ch;

        if (ch == 1) {
            s.setSaving(101, "vishal", 1000, 5);
            s.deposit(500);
            s.withdraw(200);
            s.display();
            s.interest();
        }

        else if (ch == 2) {
            c.setCheck(102, "Raj", 2000, 500);
            c.deposit(300);
            c.withdraw(2200);
            c.display();
        }

    } while (ch != 3);

    return 0;
}