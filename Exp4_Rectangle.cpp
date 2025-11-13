// Exp4_Rectangle.cpp
#include <iostream>
using namespace std;

class Rectangle {
    double length, width;
public:
    Rectangle(double l=0, double w=0): length(l), width(w) {
        // constructor
    }
    ~Rectangle() {
        // destructor
    }
    double area() const { return length * width; }
    double perimeter() const { return 2*(length + width); }
    void display() const {
        cout << "Length: " << length << ", Width: " << width
             << ", Area: " << area() << ", Perimeter: " << perimeter() << '\n';
    }
};

int main() {
    double l, w;
    cout << "Enter length and width: "; cin >> l >> w;
    Rectangle r(l,w);
    r.display();
    return 0;
}
