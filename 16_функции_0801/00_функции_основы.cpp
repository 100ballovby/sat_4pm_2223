#include <iostream>
using namespace std;

int power1() {  // определение функции без параметров
    int n, exp;
    cout << "Insert N and Expon: ";
    cin >> n >> exp;  // при вводе значений разделите числа пробелами, тогда первое будет n, а второе exp
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= n;
    }
    return res;  // вернуть фактическое значение переменной res
}

int power(int n, int exp) {  // объявление функции с параметрами
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= n;
    }
    return res;  // вернуть фактическое значение переменной res
}

void eto_vizov_power() {
    for (int i = 1; i <= 10; i++) {
        int c = power(i, 3);
        cout << i << " ^ 3 = " << c << endl;
    }
    cout << power(2, power(2, 4)) << endl;
    // позиционность аргументов
    cout << power(2, 3) << endl;  // 8
    cout << power(3, 2) << endl;  // 9
}