#include <iostream>
using namespace std;


void sum_ptrs() {  // сложение значений указателей
    int num1, num2, sum;  // память под эти переменные уже выделена
    int *ptr1, *ptr2;
    ptr1 = &num1;  // делаю ссылку на адрес ячейки, которая присвоена переменной num1
    ptr2 = &num2;

    cout << "Insert num 1: ";
    cin >> num1;  // присваиваю значение num1
    cout << "Insert num 2: ";
    cin >> num2;

    sum = (*ptr1) / (*ptr2);  // сложить адреса (значения) указателей просто так нельзя, их необходимо разыменовывать
    cout << num1 << " / " << num2  << " = " << sum << endl;
}

void print_arr_ptr() {
    int a[5] = {4, 2, 5, 1, 9};
    int *a_ptr = a;
    cout << a_ptr << endl;
    cout << &a_ptr[0] << endl;

    // вывод элементов массива через указатель
    for (int i = 0; i < 5; i++) {
        cout << a_ptr + i << "\t";  // выводятся адреса
    }
    cout << endl;
    // к адресу ячейки первого элемента массива добавляю i, благодаря этому я перехожу к следующим ячейкам
    for (int i = 0; i < 5; i++) {
        cout << *(a_ptr + i) << "\t";  // выводятся разыменованные адреса
    }
}

/* TODO: почини меня */
void need_to_fix() {
    /*Создайте два массива одинаковой
    длины и скопируйте через
    указатель элементы одного
    массива в другой*/
    int size = 5;
    int source_arr[size], target_arr[size];
    int *source_ptr = source_arr;  // создаю ссылку на первый массив
    int *target_ptr = target_arr;  // создаю ссылку на второй массив
    int *end_ptr;  // указатель на последний элемент массива

    for (int i = 0; i < size; i++) {
        cout << "Insert element: ";
        cin >> source_ptr[i];
    }

    // записываю адрес последнего элемента наполненного массива
    end_ptr = &source_ptr[size];

    while (source_ptr <= end_ptr) {  // пока адрес первого не сравнялся с адресом последнего элемента массива
        *target_ptr = *source_ptr;  // наполняю адреса "таргетного" массива элементами из оригинального массива
        source_ptr++;  // двигаюсь по элементам оригинального массива
        target_ptr++;  // двигаюсь по элементам таргетного массива
    }

    for (int i = 0; i < size; i++) {
        cout << *(source_ptr + i) << "\t";
    }
}
