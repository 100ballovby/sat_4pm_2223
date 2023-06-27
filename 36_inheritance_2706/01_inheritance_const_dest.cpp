#include <iostream>
#include <string>
using namespace std;

class Devicee {
public:
    // constructor (создание экземпляра класса)
    Devicee() {
        cout << "Devicee constructor activated" << endl;
    }
    // destructor (удаление экземпляра класса)
    ~Devicee() {
        cout << "Devicee destructor called" << endl;
    }
};


class Laptop : public Devicee {
public:
    // constructor (создание экземпляра класса)
    Laptop() {
        cout << "Laptop constructor activated" << endl;
    }
    // destructor (удаление экземпляра класса)
    ~Laptop() {
        cout << "Laptop destructor called" << endl;
    }
};

class Tablet : public Devicee {
public:
    // constructor (создание экземпляра класса)
    Tablet() {
        cout << "Tablet constructor activated" << endl;
    }
    // destructor (удаление экземпляра класса)
    ~Tablet() {
        cout << "Tablet destructor called" << endl;
    }
};



int main() {
    Laptop laptop_instance;
    Tablet tablet_instance;
    return 0;
}
