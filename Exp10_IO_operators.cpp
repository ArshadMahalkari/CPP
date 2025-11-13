// Exp10_IO_operators.cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
    int age;
public:
    Person(string n="", int a=0): name(n), age(a) {}
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }
    friend istream& operator>>(istream& is, Person& p) {
        cout << "Enter name: ";
        is.ignore(); // consume newline
        getline(is, p.name);
        cout << "Enter age: ";
        is >> p.age;
        return is;
    }
};

int main() {
    Person p;
    cin >> p;
    cout << "You entered: " << p << '\n';
    return 0;
}
