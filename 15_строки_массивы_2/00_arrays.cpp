#include <iostream>
#include <cstring>
using namespace std;

void nested_char_array() {
    int matrix[3][1] {
            {0},
            {0},
            {0}
    };
    char m_str[3][10] {
            "hellohell",
            "hellohell",
            "hellohell"
    };
    cout << matrix;
    cout << m_str;
}

void nested_fixed_char_array() {
    char m_s[3][100];
    // наполнение двумерного массива строк
    for (int i = 0; i < 3; i++) {  // для каждого вложенного массива
        cout << "type string: ";
        cin.getline(m_s[i], 100);
        // вывод двумерного массива строк
        cout << "Row " << i << ": " << m_s[i] << endl;
    }
    // второй вариант вывода двумерки
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < strlen(m_s[i]); j++) {
            cout << m_s[i][j] << "\t";
        }
        cout << endl;
    }

    // foreach
    char str[] = "hello hello hello hello";
    for (char symbol : str) {
        cout << symbol << endl;
    }

}

void mid_length_task() {
    int n, m = 100, sum = 0, mid = 0;
    cout << "N: ";
    cin >> n;
    cin.get();  // для адекватной работы getline'a

    char **m_s = new char *[n];  // создаю сам массив
    for (int i = 0; i < n; i++) {  // n раз
        m_s[i] = new char [m];  // вписываю в массив вложенные массивы (строки)
        cout << "Str: ";
        cin.getline(m_s[i], m);
        sum += strlen(m_s[i]);
        cout << m_s[i] << " length: " << strlen(m_s[i]) << endl;
    }
    mid = sum / n;
    for (int k = 0; k < n; k++){
        if (strlen(m_s[k]) < mid) {
            int index = strlen(m_s[k]);
            while (strlen(m_s[k]) < mid) {
                m_s[k][index] = ' ';
                index++;
            }
        } else if (strlen(m_s[k]) > mid) {
            int index = strlen(m_s[k]);
            while (strlen(m_s[k]) > mid) {
                m_s[k][index] = '\u0000';
                index--;
            }
        }
        cout << "'" << m_s[k] << "'";
    }
    cout << "Mid length: " << mid << endl;
    for (int c = 0; c < n; c++) {
        m_s[c] = nullptr;  // удаляем вложенные строки
    }
    m_s = nullptr;  // удаляем саму "матрицу"
}
