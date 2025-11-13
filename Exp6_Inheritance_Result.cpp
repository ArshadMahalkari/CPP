#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    string brand;
    void start() {
        cout << "Vehicle started" << endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    string model;
    void show() {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }
};

int main() {
    Car c1;
    c1.brand = "Toyota";
    c1.model = "Fortuner";
    c1.start();   // inherited function
    c1.show();    // derived class function
    return 0;
}
