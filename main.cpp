#include <iostream>
using namespace std;


class Car {
private:
    string make;
    string model;
    int year;
    string color;
public:
    Car(string brand, string series, int prod_y, string c_code) {
        this->make = brand;  // this - это указатель на объект класса
        this->model = series;
        this->year = prod_y;
        this->color = c_code;
    }

    string getMake() {
        return make;
    }

    string setMake(string make) {
        this->make = make;
    }
};

class PointCoord {
private:
    int x, y;
public:
    PointCoord(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void showCoords() {
        cout << "Coords x: " << x << "\t y: " << y << endl;
    }

    PointCoord &move(int x, int y) {
        this->x = x;
        this->y = y;
        return *this;
    }
};

int main() {
    PointCoord p1 { 20, 50 };
    p1.showCoords();
    p1.move(10, 5).move(10, 10).move(20, 20);
    p1.showCoords();
    return 0;
}
