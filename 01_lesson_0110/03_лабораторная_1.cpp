#include <iostream>
using namespace std;

void task2() {
    int b, h;
    double res;
    cout << "Введите катеты:";
    cin >> b;
    cin >> h;
    res = (b * h) * 0.5;
    cout << "S = " << res;
}

void task3() {
    int n, k, apples, remain;
    cout << "Школьники: ";
    cin >> n;
    cout << "Яблоки: ";
    cin >> k;

    apples = k / n;
    remain = k % n;
    cout << apples << " получит каждый" << endl;
    cout << remain << " останется в корзинке.";
}

void task5() {
    int n;
    cout << "Введите число: ";
    cin >> n;

    int hundreds, units, tens;
    hundreds = n / 100;
    units = n % 10;
    tens = n % 100 / 10;

    cout << n << '=' << hundreds << '+' << tens << '+' << units << '=' << hundreds + tens + units;
}