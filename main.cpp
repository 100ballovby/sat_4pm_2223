#include <iostream>
using namespace std;

void char_n_arrays() {
    char str[3][100] {
            "Hello, C++",
            "Hi there",
            "Good bye",
    };  // двумерный массив строк
    for (int i = 0; i < 3; i++) {
        cout << str[i][0] << endl;
    }
}

void char_array_fill() {
    const int n = 3, m = 100;
    char str[n][m];  // двумерный массив строк

    for (int i = 0; i < n; i++) {
        cout << "Insert string " << i + 1 << ": ";
        cin.getline(str[i], m);
    }

    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
}

void dynamic_char() {
    int n, m = 100;
    cout << "Insert how many string: ";
    cin >> n;
    cin.get();  // для игнорирования создания пустой строки после ввода
    char **str = new char *[n];  // двумерный динамический массив строк

    for (int i = 0; i < n; i++) {
        str[i] = new char[m];
        cout << "Insert string " << i + 1 << ": ";
        cin.getline(str[i], m);
    }

    // вывод "старым способом", как в матрицах
    for (int i = 0; i < n; i++) {  // перебираю строки (слова)
        for (int j = 0; j < strlen(str[i]); j++) {  // перебираю каждую букву в слове
            cout << str[i][j];  // вывожу каждую букву
        }
        cout << endl;  // перенос строки
    }

    // правильный способ вывода двумерного массива строк
    for (int i = 0; i < n; i++) {  // перебираю строки (слова)
        cout << str[i] << endl;
    }

    // высвобождение памяти динамического массива
    for (int i = 0; i < n; i++) {
        str[i] = nullptr;
    }
    str = nullptr;
}

void mid_len_str() {
    int len, string_len = 100;
    cout << "Insert how many string: ";
    cin >> len;
    cin.get();  // для игнорирования создания пустой строки после ввода
    char **str = new char *[len];  // двумерный динамический массив строк

    for (int i = 0; i < len; i++) {
        str[i] = new char[string_len];
        cout << "Insert string " << i + 1 << ": ";
        cin.getline(str[i], string_len);
    }
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += strlen(str[i]);
    }
    int mid = sum / len;
    cout << "Mid length: " << sum / len << endl;

    for (int i = 0; i < len; i++) {  // перебираю элементы двумерного массива
        if (strlen(str[i]) < mid) {  // если длина конкретного слова меньше средней длины слов
            int lst_i = strlen(str[i]);  // сохраняю в качестве индекса длину слова
            while (lst_i < mid) {  // пока этот индекс меньше средней длины
                str[i][lst_i] = ' ';  // подставляю прообел в строчку
                lst_i++;  // увеличиваю индекс
            }
        }
        else if (strlen(str[i]) > mid) {  // если длина конкретного слова больше средней длины
            int lst_i = strlen(str[i]);  // сохраняю длину слова как индекс
            while (lst_i >= mid) {  // пока этот индекс больше или равен средней длине
                str[i][lst_i] = '\u0000';  // заполоняю символ с этим индексом null
                lst_i--;  // уменьшаю индекс
            }
        }
    }
    for (int i = 0; i < len; i++) {
        cout << "'" << str[i] << "'" << endl;
    }
}

void equal_letters() {
    char str[100] = "zombie arriva at our cityc";
    str[strlen(str)] = ' ';
    int first_letter = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            int last_letter = i - 1;
            if (str[first_letter] == str[last_letter]) {
                for (int j = first_letter; j <= last_letter; j++) {
                    cout << str[j];
                }
                cout << endl;
            } else {
                first_letter = i + 1;
            }
        }
    }
}

int main() {


    return 0;
}