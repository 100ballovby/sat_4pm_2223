#include <iostream>
using namespace std;

void average_set() {
    int n, count = 0;
    double sum = 0;
    cout << "N: ";
    cin >> n;

    while (n > 0) {
        count++;  // считает количество введенных чисел
        sum += n;
        cout << "N: "; cin >> n;
    }
    cout << sum << endl;
    cout << sum / count << endl;
}

void reverse_num() {
    // развернуть число (3452 -> 2543)
    int n, reversed, tbd;
    cout << "N: "; cin >> n;

    while (n > 0) {
        tbd = n % 10;
        reversed = reversed * 10 + tbd;
        n /= 10;
    }
    cout << reversed << endl;
}

void unique_array() {
    // наполнить массив числами, которые не повторяются
    const int length = 10;
    int value; // число, которое будут вводить
    int array[length];  // массив для наполнения

    for (int i = 0; i < length; i++) {  // повторить <длина_массива> раз
        cout << "Insert value of element " << i + 1 << ": ";
        while (true) {  // цикл будет повторяться всегда, если не будет сказано иное
            cin >> value;  // вписываю число в переменную
            bool in_array = false;

            // ищу повторяющиеся числа
            for (int j = 0; j < i; j++) {  // просматриваю элементы массива с 0 до индекса i
                if (array[j] == value) {  // если какое-то число в массиве совпадает с введенным
                    in_array = true;  // ставлю статус - ЕСТЬ В МАССИВЕ
                    break;  // выхожу из цикла (потому что если нашли 1 соответствие, дальше искать не надо)
                }
            }

            if (in_array == true) {  // если введенное число найдено в массиве
                cout << value << " is in array already. Re-enter, pls: ";
            } else {  // если введенное не найдено в массиве
                break;  // выходим из цикла while
            }
        }
        array[i] = value;  // записываю число в массив, если оно уникальное
    }
}

void factorial() {
    int n, factorial = 1;
    cout << "N: "; cin >> n;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    cout << n << "! = " << factorial << endl;

    // variant 2

    factorial = 1;
    for (int i = n; i > 0; i--) {
        factorial *= i;
    }
    cout << n << "! = " << factorial << endl;
}