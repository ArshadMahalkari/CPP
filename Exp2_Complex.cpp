// Exp2_Complex.cpp
#include <iostream>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r=0, double i=0): real(r), imag(i) {}
    Complex add(const Complex & other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex subtract(const Complex & other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    void input() {
        cout << "Real: "; cin >> real;
        cout << "Imag: "; cin >> imag;
    }
    void display() const {
        cout << real << (imag>=0 ? "+" : "") << imag << "i\n";
    }
};

int main() {
    Complex a, b;
    cout << "Enter complex number A:\n"; a.input();
    cout << "Enter complex number B:\n"; b.input();
    cout << "A + B = "; a.add(b).display();
    cout << "A - B = "; a.subtract(b).display();
    return 0;
}
