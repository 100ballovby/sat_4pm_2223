#include <iostream>
using namespace std;


void for_basics() {
    // цикл с управляющей переменной i (считает повторения)
    for (int i = 0; i < 10; i += 1) {  // название переменной может быть любым, но лучше i - iteration
        cout << "i = " << i << endl;
    } // обратиться к значению i можно ТОЛЬКО внутри цикла
}

void for_power() {
    // написать программу возведения числа num в степень exp
    int num, exp;
    cout << "Insert num: ";
    cin >> num;
    cout << "Insert exp: ";
    cin >> exp;

    int total = 1;  // эту переменную мы будем умножать
    for (int i = 0; i < exp; i += 1) {
        total *= num;  // введенное пользователем число умножаю само на себя в переменной
    }
    cout << num << "^" << exp << " = " << total << endl;
}

void for_reverse() {
    for (int i = 10; i > -1; i -= 1) {
        // запустим цикл в обратную сторону от 10 до 0
        cout << i << endl;
    }
}

void for_stars() {
    // лесенка из звездочек
    int stars;
    cout << "How many stars? ";
    cin >> stars;

    for (int i = 1; i <= stars; i += 1) {
        // рисует ступеньки
        for (int j = 1; j <= i; j += 1) {
            // рисует звездочки
            cout << "*"; // без endl (без переноса на строку)
        }
        cout << endl;
    }
}