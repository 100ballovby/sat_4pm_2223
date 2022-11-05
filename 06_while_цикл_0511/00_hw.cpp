#include <iostream>
#include <cmath>
using namespace std;

int randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}

void hw_task_1_and_2() {
    srand(time(NULL));
    const int n = 15;
    int arr[n], max, i_max;
    for (int i = 0; i < n; i++) {
        arr[i] = randint(-100, 100);
        cout << arr[i] << ", ";
    }
    max = arr[0];
    i_max = -1;
    for (int i = 1; i < n; i++) {
        if (abs(arr[i]) > max) {  // если элемент массива больше max
            max = abs(arr[i]);  // присвоить max значение этого элемента
            i_max = i;  // сохранить индекс самого большого элемента
        }
    }
    cout << endl << endl;
    cout << "Max element: " << max << endl;
    cout << "Index of max element: " << i_max << endl;

    // посчитать сумму элементов, стоящих ПОСЛЕ максимального
    int summ = 0;
    for (int i = i_max; i < n; i++) {
        cout << arr[i] << endl;
        summ += arr[i];
    }
    cout << summ << endl;
}