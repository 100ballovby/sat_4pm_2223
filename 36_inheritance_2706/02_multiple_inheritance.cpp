#include <iostream>
#include <string>
using namespace std;

class WorkStation {
public:
    void turn_on() {
        cout << "Welcome to Windows 95" << endl;
    }
};

class Monitor {
public:
    void show_image() {
        cout << "Showing image..." << endl;
    }
};

class Ultrabook : public WorkStation, public Monitor {};  // множественное наследование

int main_inheritance_3() {
    Ultrabook acer_aspire_5;
    acer_aspire_5.turn_on();
    acer_aspire_5.show_image();
    return 0;
}
