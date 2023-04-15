#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Rectangle {
    int width, height;
    int area;

    void set_width(int w) {
        this->width = w;
    }

    void set_height(int h) {
        this->height = h;
    }

    int count_area() {
        return this->height * this->width;
    }
};


int hw_struct_task_rect() {
    Rectangle rect;
    rect.set_width(100);
    rect.set_height(200);
    int ar = rect.count_area();
    cout << ar << endl;
    return 0;
}