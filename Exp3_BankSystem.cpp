// Exp3_BankSystem.cpp
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accNo;
    string name;
    double balance;
public:
    Account(string a="", string n="", double b=0.0): accNo(a), name(n), balance(b) {}
    virtual ~Account() {}
    virtual void deposit(double amt) { balance += amt; }
    virtual bool withdraw(double amt) {
        if (amt <= balance) { balance -= amt; return true; }
        return false;
    }
    virtual void display() const {
        cout << "Acc No: " << accNo << "\nName: " << name << "\nBalance: " << balance << '\n';
    }
};

class Savings : public Account {
    double minBalance;
public:
    Savings(string a="", string n="", double b=0.0, double m=500): Account(a,n,b), minBalance(m) {}
    bool withdraw(double amt) override {
        if (balance - amt >= minBalance) { balance -= amt; return true; }
        return false;
    }
};

class Checking : public Account {
    double overdraftLimit;
public:
    Checking(string a="", string n="", double b=0.0, double od=1000): Account(a,n,b), overdraftLimit(od) {}
    bool withdraw(double amt) override {
        if (balance + overdraftLimit >= amt) { balance -= amt; return true; }
        return false;
    }
};

int main() {
    Savings s("S001","Alice",2000,500);
    Checking c("C001","Bob",500,1000);
    cout << "Before transactions:\n";
    s.display(); cout << '\n';
    c.display(); cout << '\n';

    s.deposit(500);
    if (s.withdraw(1900)) cout << "Savings: Withdrawal success\n"; else cout << "Savings: Withdrawal failed\n";
    if (c.withdraw(1200)) cout << "Checking: Withdrawal success\n"; else cout << "Checking: Withdrawal failed\n";

    cout << "\nAfter transactions:\n";
    s.display(); cout << '\n';
    c.display(); cout << '\n';
    return 0;
}
