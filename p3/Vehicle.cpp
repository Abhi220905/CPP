#include <iostream>
using namespace std;

class Vehicle {
protected:
    int id, year;
    string name, model;

public:
    void setData(int i, string n, string m, int y) {
        id = i;
        name = n;
        model = m;
        year = y;
    }

    void show() {
        cout << id << " " << name << " " << model << " " << year << endl;
    }
};

class Car : public Vehicle {
    string fuel;

public:
    void setCar(int i, string n, string m, int y, string f) {
        setData(i, n, m, y);
        fuel = f;
    }

    void showCar() {
        show();
        cout << fuel << endl;
    }
};

class Registry {
    Car c[10];
    int count = 0;

public:
    void add() {
        int id, year;
        string name, model, fuel;

        cin >> id >> name >> model >> year >> fuel;
        c[count].setCar(id, name, model, year, fuel);
        count++;
    }

    void display() {
        for (int i = 0; i < count; i++) {
            c[i].showCar();
        }
    }
};

int main() {
    Registry r;
    int ch;

    do {
        cout << "1.Add 2.Show 3.Exit\n";
        cin >> ch;

        if (ch == 1) r.add();
        else if (ch == 2) r.display();

    } while (ch != 3);

    return 0;
}