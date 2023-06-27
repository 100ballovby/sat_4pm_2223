#include <iostream>
#include <string>
using namespace std;

class Device {
public:
    int serial_number = 12345678;
    void turn_on() {
        cout << "Device is on" << endl;
    }
private:
    int service_pin = 88888;
};

class Computer : private Device {
public:
    void say_hello() {
        turn_on();
        cout << "Hello, world!" << endl;
    }
};  // класс computer унаследован от класса Device

/** Наследование в С++ бывает трех видов
 * public - при наследовании способом public ВСЕ данные становятся публичными
 * private - все унаследованные данные становятся приватными
 * protected - все унаследованные данные становятся защищенными
 * **/

int inheritance_start() {
    Device device_instance;
    Computer computer_instance;

    cout << "Device info\t";
    cout << device_instance.serial_number << endl;

    cout << "Computer: " << endl;
    computer_instance.say_hello();
    return 0;
}
