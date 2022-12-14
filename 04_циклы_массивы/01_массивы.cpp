#include <iostream>
using namespace std;


void arrays_basics() {
    int marks[5];  // объявил фиксированный целочисленный массив на 5 элементов
    // наполним массив числами
    marks[0] = 9; // на место первого элемента ставим число 9
    marks[1] = 6;
    marks[2] = 8;
    marks[3] = 2;
    cout << marks[1] * 2;  // обращаюсь к элементу по индексу и умножаю его на 2
    // индекс - это порядковый номер элемента в массиве
}

void arrays_size() {
    int marks[] = {9, 6, 8, 2, 7}; // инициализировал целочисленный фиксированный массив на 5 элементов
    cout << marks[1] * 2 << endl;  // обращаюсь к элементу по индексу и умножаю его на 2
    // хочу узнать размер массива
    cout << "Размер массива = " << sizeof(marks) << endl;  // оператор sizeof выдает ответ в битах
    // чтобы узнать количество элементов в массиве, нужно разделить размер массива на размер одного из его элементов
    cout << "Количество элементов = " << sizeof(marks) / sizeof(marks[0]) << endl;
}

void arrays_cout() {
    int marks[] = {9, 6, 8, 2, 7};
    // для того, чтобы вывести массив, его нужно перебрать циклом
    // перебрать = вывести каждый элемент массива по его индексу
    for (int i = 0; i < 5; i += 1) {
        cout << "marks[" << i << "] = " << marks[i] << endl;
    }

    for (int i = 0; i < 5; i += 1) {
        cout << marks[i] << ", ";
    }
}

void arrays_inserting() {
    /* Нужно написать программу, которая запросит у пользователя
     * числа и впишет их в массив. */
    const int length = 5;
    int marks[length];  // объявляю массив длинной равной значению константы
    for (int i = 0; i < length; i += 1) {  // количество повторений цикла = длине массива
        int n;
        cout << "Insert value for index " << i << ": ";
        cin >> n;

        marks[i] = n;  // на место элемента с индексом i вписать число, введенное пользователем
    }
    for (int i = 0; i < length; i += 1) {
        cout << marks[i] << ", ";
    }
}