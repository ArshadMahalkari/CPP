// Exp5_FunctionOverload_Shapes.cpp
#include <iostream>
#include <cmath>
using namespace std;

double area(double radius) { // circle
    return M_PI * radius * radius;
}
double area(double length, double width) { // rectangle
    return length * width;
}
double area(double base, double height, int) { // triangle (third parameter to differentiate)
    return 0.5 * base * height;
}

int main() {
    cout << "Circle radius 3 -> area: " << area(3.0) << '\n';
    cout << "Rectangle 4 x 5 -> area: " << area(4.0,5.0) << '\n';
    cout << "Triangle base 4 height 6 -> area: " << area(4.0,6.0,0) << '\n';
    return 0;
}
