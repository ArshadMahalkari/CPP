// Exp13_ExceptionHandling.cpp
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InvalidAgeException : public runtime_error {
public:
    InvalidAgeException(const string& msg): runtime_error(msg) {}
};

void validateAge(int age) {
    if (age < 0 || age > 150) throw InvalidAgeException("Age out of valid range");
}

int safeDivide(int a, int b) {
    if (b == 0) throw runtime_error("Division by zero");
    return a / b;
}

int main() {
    try {
        cout << "Enter two integers (a b): ";
        int a,b; cin >> a >> b;
        cout << "a/b = " << safeDivide(a,b) << '\n';
    } catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    try {
        cout << "Enter age to validate: ";
        int age; cin >> age;
        validateAge(age);
        cout << "Age is valid\n";
    } catch (const InvalidAgeException& e) {
        cout << "InvalidAgeException: " << e.what() << '\n';
    }
    return 0;
}
