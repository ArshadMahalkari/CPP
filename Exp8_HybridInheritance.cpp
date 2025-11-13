// Exp8_HybridInheritance.cpp
#include <iostream>
#include <string>
using namespace std;

// Base
class Person {
protected:
    string name;
public:
    Person(string n=""): name(n) {}
    void setName(const string& n) { name = n; }
    void showName() const { cout << "Name: " << name << '\n'; }
};

// Derived A (single)
class Student : public Person {
protected:
    int roll;
public:
    Student(string n="", int r=0): Person(n), roll(r) {}
    void setStudent(int r) { roll=r; }
    void showStudent() const { cout << "Student Roll: " << roll << '\n'; }
};

// Derived B (single)
class Employee : public Person {
protected:
    int empId;
public:
    Employee(string n="", int e=0): Person(n), empId(e) {}
    void setEmployee(int e) { empId = e; }
    void showEmployee() const { cout << "Employee ID: " << empId << '\n'; }
};

// Hybrid: TeachingAssistant is both Student and Employee (note: two Person subobjects)
class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string name="", int roll=0, int emp=0)
    : Student(name, roll), Employee(name, emp) {}
    void display() const {
        // Ambiguity: need to specify which Person::showName
        cout << "TA info:\n";
        Student::showName(); // name from Student->Person
        showStudent();
        showEmployee();
    }
};

int main() {
    TeachingAssistant ta("Ravi", 45, 1001);
    ta.display();
    return 0;
}
