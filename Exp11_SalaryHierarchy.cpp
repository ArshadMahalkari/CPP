// Exp11_SalaryHierarchy.cpp
#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
public:
    Employee(string n=""): name(n) {}
    virtual double calculateSalary() const = 0;
    virtual void display() const {
        cout << "Employee: " << name << '\n';
    }
    virtual ~Employee() {}
};

class SalariedEmployee : public Employee {
    double monthlySalary;
public:
    SalariedEmployee(string n, double sal): Employee(n), monthlySalary(sal) {}
    double calculateSalary() const override { return monthlySalary; }
};

class HourlyEmployee : public Employee {
    double hours;
    double rate;
public:
    HourlyEmployee(string n, double h, double r): Employee(n), hours(h), rate(r) {}
    double calculateSalary() const override { return hours * rate; }
};

class CommissionedEmployee : public Employee {
    double sales;
    double commissionRate;
public:
    CommissionedEmployee(string n, double s, double cr): Employee(n), sales(s), commissionRate(cr) {}
    double calculateSalary() const override { return sales * commissionRate; }
};

int main() {
    SalariedEmployee se("Anna", 4000);
    HourlyEmployee he("Ben", 160, 15);
    CommissionedEmployee ce("Cara", 50000, 0.05);

    cout << se.calculateSalary() << '\n';
    cout << he.calculateSalary() << '\n';
    cout << ce.calculateSalary() << '\n';
    return 0;
}
