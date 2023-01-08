#include <iostream>
#include <string>
using namespace std;


int power(int n, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= n;
    }
    return res;  // вернуть фактическое значение переменной res
}

string to_binary(int n) {
    string bin = "";  // здесь будем хранить двоичное число
    while (n > 0) {  // пока n не стало 0
        bin = char('0' + n % 2) + bin;  // записываем остатки от деления на 2
        /** Когда вы пишете += -> bin = bin + что-то (остатки от деления
         * записываются в конец строки)
         * Когда вы пишете bin = что-то + bin -> остатки от деления
         * записываются в обратную сторону **/
        n /= 2;  // саму n уменьшаем путем деления на 2
    }
    return bin;
}

int to_decimal(string bin_n) {
    int dec = 0;  // число в десятеричной системе счисления
    int len = bin_n.length();  // длина бинарного числа
    for (int i = 0; i < len; i++) {  // проходимся по каждому символу строки
        if (bin_n[len - 1 - i] == '1') {  // если цифра (с конца) равна 1
            dec += power(2, i);  // добавляем число в степени этого индекса к десятеричной записи
        }
    }
    return dec;
}

void eto_main_dlya_binarnih_funktsiy() {

    int n;
    cout << "Insert n: ";
    cin >> n;
    string binary = to_binary(n);
    cout << n << " in binary is " << binary << endl;
    cout << binary << " in decimal is " << to_decimal(binary) << endl;
}