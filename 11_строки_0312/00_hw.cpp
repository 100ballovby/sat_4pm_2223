#include <iostream>
using namespace std;


int hw_matrix_0312() {
    int n, m;
    cout << "Insert n:" << endl;
    cin >> n;
    cout << "Insert m:" << endl;
    cin >> m;

    int **matrix1 = new int *[n];
    int **matrix2 = new int *[n];

    cout << "Matrix 1: " << endl;
    for (int i = 0; i < n; i++) {
        matrix1[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrix1[i][j] = rand() % (-100 - (100));
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Matrix 2: " << endl;
    for (int i = 0; i < n; i++) {
        matrix2[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrix2[i][j] = rand() % (-100 - (100));
            cout << matrix2[i][j] << "\t";
        }
        cout << endl;
    }

    // сложим матрицы
    cout << endl << "Сложение матриц" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix1[i][j] + matrix2[i][j] << "\t";
            // для умножения матриц поменяйте + на *
        }
        cout << endl;
    }

    // внесем минус в матрицу
    cout << endl << "Внесение минуса" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix1[i][j] *= -1;
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }

    // умножение матрицы
    cout << endl << "Умножение на 6" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix1[i][j] *= 6;
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }
    // очистим память от массивов
    for (int i = 0; i < n; i++) {
        matrix1[i] = nullptr;
        matrix2[i] = nullptr;
    }
    matrix1 = nullptr;
    matrix2 = nullptr;
    return 0;
}