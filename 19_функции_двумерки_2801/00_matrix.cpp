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

void bubble_sort(int *array, int size) {
    // цикл, который будет отсматривать каждый элемент массива
    for (int i = 0; i < size - 1; i++) {
        // цикл, который будет заниматься сравнением элементов массива
        for (int j = 0; j < size - i - 1; j++) {  // последний элемент всегда отсортирован, поэтому его не трогаем
            // если текущий элемент меньше следующего,
            // их нужно поменять местами
            if (array[j] < array[j + 1]) {
                swap(array[j], array[j + 1]);  // меняет местами array[i] и array[i + 1]
            }
        }
    }
}

void task_teams() {
    /* На соревнованиях по прыжкам в длину принимает участие n команд по
 * 5 человек в каждой. Общий результат – это суммарный результат всех игроков
 * команды. Вывести на экран номера команд, которые заняли первые
 * три места и их результат.
*/
    int n;
    cout << "Teams: ";
    cin >> n;
    int **teams = new int *[n];
    int *top = new int[n];  // здесь буду хранить общие результаты команд
    fill_matrix(teams, n);
    print_matrix(teams, n, 5);
    // здесь посчитаем общие результаты команд
    for (int i = 0; i < n; i++) {  // просматриваю каждую строку (каждую команду)
        int sum = 0;  // завожу переменную для подсчета суммы очков
        for (int j = 0; j < 5; j++) {  // каждый результат каждого члена команды
            sum += teams[i][j];  // суммирую
        }
        top[i] = sum;  // добавляю сумму команды в массив
        cout << top[i] << ", ";  // вывожу ее
    }

    bubble_sort(top, n);  // сортирую массив с результатами команд
    // выведем победителей
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "st place team has " << top[i] << " scores!" << endl;
    }
}

int task_charasteristics() {
    srand(time(NULL));
    int n;
    cout << "N: "; cin >> n;
    int **matrix = new int *[n];
    int *characteristics = new int [n];
    fill_matrix(matrix, n);
    print_matrix(matrix, n, 5);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            int elem = matrix[i][j];
            if (elem > 0 && elem % 2 == 0) {
                sum += elem;
            }
        }
        characteristics[i] = sum;
        cout << "Line " << i << " char. is " << characteristics[i] << endl;
    }


    return 0;
}