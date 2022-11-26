#include <iostream>
using namespace std;


int randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}

void dynamic_matrix() {
    int n, m;
    cout << "Insert n: ";
    cin >> n;
    cout << "Insert m: ";
    cin >> m;

    // объявление динамической матрицы
    /* Вторая (справа) звезда указывает на вложенные массивы,
     * первая (слева) звезда указывает на саму матрицу */
    int **matrix = new int *[n];  // создание "обертки" вложенных массивов
    for (int stroka = 0; stroka < n; stroka++) {  // в каждой строчке матрицы
        matrix[stroka] = new int[m];  // объявить новый массив длиной m
    }
    srand(time(NULL));
    // наполнение динамической матрицы случайными числами
    for (int i = 0; i < n; i++) {  // в строках
        for (int j = 0; j < m; j++) {  // в столбцах
            matrix[i][j] = randint(-3, 5);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Main diagonal matrix: " << endl;
    // вывод элементов главной диагонали матрицы
    for (int i = 0; i < n; i++) {
        cout << matrix[i][i] << "\t";
    }
    cout << endl;
    cout << "Side diagonal matrix: " << endl;
    // вывод элементов побочной диагонали матрицы
    for (int i = 0; i < n; i++) {
        cout << matrix[i][n - 1 - i] << "\t";
    }



    // чтобы удалить динамическую матрицу,
    // нужно сначала удалить все вложенные массивы,
    // а только потом удалять саму матрицу
    for (int i = 0; i < n; i++) {
        matrix[i] = nullptr;  // удаляю каждую строку (присваиваю ей нулевой указатель)
    }
    matrix = nullptr;  // удаляю саму матрицу
    // cout << matrix[0][0] << endl;  <- обращение невозможно, потому что
    // матрицы больше нет.
}