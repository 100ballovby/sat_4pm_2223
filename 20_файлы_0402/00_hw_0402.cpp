#include <iostream>
using namespace std;

int randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}

void fill_matrix(int **array, int lines) {
    const int cols = 5;
    for (int i = 0; i < lines; i++) {
        array[i] = new int[cols];  // создаем вложенный массив на определенное количество элементов
        for (int j = 0; j < cols; j++) {
            array[i][j] = randint(0, 20);  // заполняем элементы матрицы
        }
    }
}

void print_matrix(int **array, int lines, int cols) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void hw_matrix_first_zero() {
    int n, found_line, first_elem;
    cout << "Insert n: ";
    cin >> n;
    int **matrix = new int *[n];
    fill_matrix(matrix, n);
    print_matrix(matrix, n, n);
    for (int i = 0; i < n; i++) {  // перебираю строки матрицы
        for (int j = 0; j < n; j++) {  // перебираю элементы строк матрицы
            if (matrix[i][j] == 0) {  // если конкретный элемент равен 0
                found_line = i;  // записать i (индекс строки) в переменную
                break;  // закончить поиск
            }
        }
    }
    first_elem = matrix[found_line][0];  // сохраняю первый элемент найденной строки матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] -= first_elem;  // каждый элемент матрицы уменьшаю на значение первого элемента найденной строоки
        }
    }
    print_matrix(matrix, n, n);
}