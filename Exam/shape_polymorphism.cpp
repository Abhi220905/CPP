#include <iostream>
#include <cmath>

using namespace std;

// Abstract Base Class
class Shape {
public:
    // Pure virtual functions
    virtual void calculateArea() = 0;
    virtual void draw() = 0;
    
    virtual ~Shape() {}
};

// Concrete Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void calculateArea() override {
        double area = M_PI * radius * radius;
        cout << "Circle Area: " << area << endl;
    }

    void draw() override {
        cout << "Drawing a Circle with radius " << radius << endl;
    }
};

// Concrete Class: Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void calculateArea() override {
        double area = width * height;
        cout << "Rectangle Area: " << area << endl;
    }

    void draw() override {
        cout << "Drawing a Rectangle (" << width << "x" << height << ")" << endl;
    }
};

int main() {
    // Array of Shape pointers (Polymorphism)
    Shape* shapes[2];

    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    cout << "--- Shape Demonstration ---" << endl;
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        shapes[i]->calculateArea();
        cout << endl;
    }

    // Cleanup
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }

    return 0;
}
