#include <iostream>
using namespace std;

void ran_gen() {
    srand(time(NULL));  // начало точки отсчета случайных чисел
    // будет браться как текущее значение времени во время запуска кода
    cout << rand() % 100 - 5 << endl;  // генерировать случайное целое число

}

int randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    srand(time(NULL));
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}

void some_numbers() {
    int quantity;
    cout << "How many random nums do u need? ";
    cin >> quantity;
    for (int i = 0; i < quantity; i++) {
        cout << -10 + rand() % (10 - (-10) + 1) << endl;
    }
}

int linear_search(int array[], int key, int len) {
    /** Алгоритм линейногоо поиска просматривает
     * каждый элемент массива arr и сравнивает его с
     * искомым числом key. Как только числа совпадают,
     * поиск прекращается и должно быть возвращен индекс
     * найденного в массиве элемента **/
    for (int i = 0; i < len; i++) {
        if (array[i] == key) {  // если число в массиве совпадает с искомым
            return i;  // возвращаю индекс элемента (если найден)
        }
    }
    return -1;  // вернем -1, как показатель того, что ничего нет
}

void lin_search_use() {
    int k;
    cout << "Key: ";
    cin >> k;
    /*for (int i = 0; i < quantity; i++) {
        cout << -10 + rand() % (10 - (-10) + 1) << endl;
    } */
    int arr[] = {4, 7, 12, 2, 6, 10, 9, -1, 6};
    int len = sizeof(arr) / sizeof(arr[0]); // измеряю количество элементов массива
    cout << linear_search(arr, k, len) << endl;
}

void goto_operator() {
    int num;

    tryAgain:  // метка возврата в начало
    cout << "Insert: ";
    cin >> num;

    if (num % 2 != 0) {  // если ввели нечетное число
        goto tryAgain;  // вернуть пользователя в метку tryAgain
    }
    // этот код исполнится только если условие будет верным
    cout << num << " is even" << endl;
}

void task_1_arrays() {
    /* наполнить массив случайными числами,
     * найти наибольший и наименьший его элементы
     * и поменять их местами */
    int max, min, i_max, i_min;
    const int n = 30;
    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {  // наполняю массив числами
        arr[i] = rand() % (100 - 1 + 1) + 1;
        cout << arr[i] << ", ";
    }
    i_max = 0;  // индекс наибольшего 0
    i_min = 0;  // индекс наименьшего 0
    max = arr[0];  // наибольший элемент массива - первый элемент массива
    min = arr[0];  // наименьшеший элемент массива - первый элемент массива
    for (int i = 0; i < n; i++) {  // перебираю элементы массива
        if (max < arr[i]) {  // число в массиве больше того, что записано в max
            max = arr[i];  // считаю, что это число наибольшее
            i_max = i;  // сохраняю индекс наибольшего элемента
        }
        if (min > arr[i]) {  // число в массиве меньше того, что записано в min
            min = arr[i];  // считаю, что это число наименьшее
            i_min = i;  // сохраняю индекс наименьшего элемента
        }
    }
    cout << endl;
    cout << "Max = " << max << ", Index = " << i_max << endl;
    cout << "Min = " << min << ", Index = " << i_min << endl;
    // меняю местами максимальный и минимальный элемент
    arr[i_min] = max;
    arr[i_max] = min;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
}