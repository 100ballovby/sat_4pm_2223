#include <iostream>
using namespace std;

void hw_arr_task1() {
    int arr[7];
    // Вычислить произведение элементов с четными индексами
    int mult = 1;
    // четные индексы - 0, 2, 4, 6. То есть i увеличивается на 2
    for (int i = 0; i < 7; i += 2) {
        mult *= arr[i];
    }
    cout << mult << endl;
    // сумма элементов, расположенных до последнего положительного
    int summ = 0;
    int last_pos = -1;  // индекс последнего положительного
    for (int j = 6; j > -1; j--) {
        if (arr[j] > 0) {  // если элемент положительный
            last_pos = j;  // присвоить его индекс в массиве переменной j
            break;  // остановить поиск, когда нашли первый (последний) положительный
        }
    }
    cout << last_pos << endl;
    for (int k = 0; k <= last_pos; k++) {
        summ += arr[k];
    }
    cout << summ << endl;
}

void hw_arr_task2() {
    int arr[8] = {-3, 0, 4, 2, 0, -9, 14, -7};

    // вычислить сумму положительных
    int summ = 0;
    for (int i = 0; i < 8; i++) {
        if (arr[i] > 0) {  // если элемент положительный
            summ += arr[i];
        }
    }
    cout << summ << endl;
    // посчитать сумму элементов, стоящих после последнего нуля
    summ = 0;  // обнуляю значение суммы
    for (int j = 7; j > -1; j--) {
        summ += arr[j];
        if (arr[j] == 0) {  // если элемент равен 0
            break;  // остановить цикл
        }
    }
    cout << summ << endl;
}