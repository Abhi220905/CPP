#include <iostream>
#include <string>

using namespace std;

// Base Class
class Vehicle {
protected:
    string model;
    double speed;

public:
    Vehicle(string m, double s) : model(m), speed(s) {}

    // Virtual function for polymorphism
    virtual void displayDetails() {
        cout << "Vehicle Model: " << model << " | Speed: " << speed << " km/h" << endl;
    }

    virtual ~Vehicle() {} // Virtual destructor for proper cleanup
};

// Derived Class: Car
class Car : public Vehicle {
public:
    Car(string m, double s) : Vehicle(m, s) {}

    void displayDetails() override {
        cout << "[Car] Model: " << model << " | Speed: " << speed << " km/h | Type: 4-Wheeler" << endl;
    }
};

// Derived Class: Bike
class Bike : public Vehicle {
public:
    Bike(string m, double s) : Vehicle(m, s) {}

    void displayDetails() override {
        cout << "[Bike] Model: " << model << " | Speed: " << speed << " km/h | Type: 2-Wheeler" << endl;
    }
};

int main() {
    // Array of Vehicle pointers
    Vehicle* vehicles[2];

    vehicles[0] = new Car("Audi A6", 150.0);
    vehicles[1] = new Bike("Ducati Panigale", 180.0);

    cout << "--- Polymorphism in Action ---" << endl;
    for (int i = 0; i < 2; i++) {
        // Polymorphism: Calling the correct displayDetails() at runtime
        vehicles[i]->displayDetails();
    }

    // Cleanup
    for (int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}
