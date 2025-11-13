// Exp7_MultipleInheritance_Edu.cpp
#include <iostream>
#include <string>
using namespace std;

// Base 1
class PersonalInfo {
protected:
    string name;
    int age;
public:
    PersonalInfo(string n="", int a=0): name(n), age(a) {}
    void setPersonal(const string& n, int a) { name = n; age = a; }
    void showPersonal() const { cout << "Name: " << name << ", Age: " << age << '\n'; }
};

// Base 2
class AcademicInfo {
protected:
    string course;
    int year;
public:
    AcademicInfo(string c="", int y=0): course(c), year(y) {}
    void setAcademic(const string& c, int y) { course = c; year = y; }
    void showAcademic() const { cout << "Course: " << course << ", Year: " << year << '\n'; }
};

// Derived class inherits both
class StudentRecord : public PersonalInfo, public AcademicInfo {
    int roll;
public:
    StudentRecord(int r=0): roll(r) {}
    void setAll(int r, const string& n, int a, const string& c, int y) {
        roll = r;
        setPersonal(n,a);
        setAcademic(c,y);
    }
    void display() const {
        cout << "Roll: " << roll << '\n';
        showPersonal();
        showAcademic();
    }
};

int main() {
    StudentRecord s;
    s.setAll(11,"Asha",19,"BSc CS",2);
    s.display();
    return 0;
}
