#include <iostream>
using namespace std;

int task1_hw_arrays(int *array, int size) {
    int found;  // здесь будем сохранять индекс найденного элемента
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            found = i;
            break;  // выйти из цикла, после того, как найден первый отрицательный
        }
    }
    return found;
}

bool task2_hw_arrays(int *array, int size) {
    bool all_even = true;  // по умолчанию я считаю, что все элементы массива четные
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0) {  // если встретили нечетный элемент
            all_even = false;  // присвоить флагу false
            break;  // выйти из цикла
        }
    }
    return all_even;  // вернуть значение all_even (если все хорошо, оно будет true, если нет - false)
}

int запускай_меня() {
    int a[] = {4, 2, -11, -4, 5, -6, 2};
    int b[] = {10, 8, 0, 14, 120, 220};
    cout << task2_hw_arrays(a, 7) << endl;
    cout << task2_hw_arrays(b, 6) << endl;
    return 0;
}