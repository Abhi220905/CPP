#include <iostream>
#include <string>

using namespace std;

// Base Class
class Vehicle {
private:
    string model;
    double speed;

public:
    // Setters
    void setModel(string m) { model = m; }
    void setSpeed(double s) { speed = s; }

    // Getters
    string getModel() { return model; }
    double getSpeed() { return speed; }
};

// Derived Class: Car
class Car : public Vehicle {
public:
    void calculateTime(double distance) {
        if (getSpeed() > 0) {
            double time = distance / getSpeed();
            cout << "Car (" << getModel() << ") will take " << time << " hours for " << distance << " km." << endl;
        }
    }
};

// Derived Class: Bike
class Bike : public Vehicle {
public:
    void calculateTime(double distance) {
        if (getSpeed() > 0) {
            double time = distance / getSpeed();
            cout << "Bike (" << getModel() << ") will take " << time << " hours for " << distance << " km." << endl;
        }
    }
};

int main() {
    Car myCar;
    myCar.setModel("Tesla Model S");
    myCar.setSpeed(120.0);

    Bike myBike;
    myBike.setModel("Yamaha R1");
    myBike.setSpeed(80.0);

    double distance = 240.0;
    
    // Demonstrating abstraction by calling time calculation methods
    myCar.calculateTime(distance);
    myBike.calculateTime(distance);

    return 0;
}
