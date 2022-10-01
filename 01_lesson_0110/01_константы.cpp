#include <iostream>
using namespace std;

void circle() {
    const double pi = 3.1415926; // инициализация константы
    int r;
    cout << "Введи радиус: ";
    cin >> r;
    // если удалить "//" снизу, то будет ошибка
    // pi = 345;
    cout << "S = " << pi * (r * r);
}