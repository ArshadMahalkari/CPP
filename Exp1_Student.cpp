// Exp1_Student.cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int roll;
    float marks;
public:
    Student() : name(""), roll(0), marks(0.0f) {}
    Student(string n, int r, float m) : name(n), roll(r), marks(m) {}
    void input() {
        cout << "Name: "; getline(cin, name);
        cout << "Roll: "; cin >> roll;
        cout << "Marks: "; cin >> marks;
        cin.ignore();
    }
    void display() const {
        cout << "Student details\n";
        cout << "Name: " << name << "\nRoll: " << roll << "\nMarks: " << marks << '\n';
    }
};

int main() {
    Student s;
    cout << "Enter student details:\n";
    s.input();
    cout << '\n';
    s.display();
    return 0;
}
