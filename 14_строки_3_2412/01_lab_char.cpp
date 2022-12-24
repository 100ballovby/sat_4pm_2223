#include <iostream>
using namespace std;

void char_remember() {
    char ch1 (107);
    char array[100] = {"hello, andrew"};
    cout << array << endl;
    array[5] = '!';
    for (int i = 0; i < strlen(array); i++) {
        cout << array[i] << ", ";
    }
    char symbol;
    cout << "Type letters, end with enter: ";
    cin.getline(array, 100);

    for (int i = 0; i < strlen(array); i++) {
        cout << array[i] << ", ";
    }
}

void is_palindrome() {
    char string[100];
    cout << "Type smth: ";
    cin.getline(string, 100);
    int size = strlen(string);
    bool is_palindrome = true;
    for (int i = 0; i < size; i++) {
        if (string[i] != string[size - 1 - i]) {  // если символ из начала строки не совпадает с символом с конца строки
            is_palindrome = false;  // присвоить false
            break;  // выйи из цикла
        }
    }
    if (is_palindrome) {
        cout << string << " is palindrome" << endl;
    } else {
        cout << string << " isn't palindrome" << endl;
    }
}

void count_digits() {
    /* В строке, состоящей из групп нулей и единиц посчитать количество
     * единиц в группах с нечетным количеством символов. */
    char string[100];
    cout << "Type smth: ";
    cin.getline(string, 100);
    int size = strlen(string);
    int count_one = 0, count_odd_one = 0;
    for (int i = 0; i < size; i++) {
        if (string[i] == '1') {  // сравниваю символы с единицей
            count_one++;  // если нашли 1, добавляем к общему количеству
        } else if (string[i] == '0') {  // как только встречен 0
            if (count_one % 2 != 0) {  // проверить, что количество единиц до встреченного нуля нечетное
                count_odd_one += count_one;  // если нечетное, добавить количество этих единиц к переменной
            }
            count_one = 0;  // сбросить счетчик единиц
        }
    }
    cout << count_odd_one << endl;
}

void fill_string_with_spaces() {
    char string[100];
    cout << "Type smth: ";
    cin.getline(string, 100);
    int size = strlen(string), n;

    // Заполнить строку пробелами, пока ее длина не будет равна n
    cout << "Insert n: ";
    cin >> n;
    /* Функция strlen() меряет длину строки до последнего символа перед NUL */
    while (strlen(string) < n) {
        string[size] = ' ';
        size++;
    }
    cout << "'" << string << "'" << endl;
}