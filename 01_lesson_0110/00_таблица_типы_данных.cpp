#include <iostream>
using namespace std;

void table() {
    cout << "Размеры встроенных типов" << endl;

    cout << "bool: " << sizeof(bool) << endl;
    cout << "char: " << sizeof(char) << endl;
    cout << "unsigned short int: " << sizeof(unsigned short int) << endl;
    cout << "short int: " << sizeof(short int) << endl;
    cout << "long int: " << sizeof(long int) << endl;
    cout << "long long: " << sizeof(long long) << endl;
    cout << "float: " << sizeof(float) << endl;
    cout << "double: " << sizeof(double) << endl;
}