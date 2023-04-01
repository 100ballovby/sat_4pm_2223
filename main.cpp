#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct NumSq {
    int number;
    double num_square;
};

bool my_comparison(const NumSq &a, const NumSq &b) {
    // передаем функции ссылки на элементы структуры
    return a.number < b.number;  // и сравниваем, кто из двух элементов имеет бОльшее значение
}

int main() {
    srand(time(NULL));
    int n = 121;
    cout << sqrt(n) << endl;
    cout << pow(n, 3) << endl;

    double sq = pow(3, 2) + pow(8, 2);
    cout << sqrt(sq) << endl;

    // наполнить вектор квадратами первых 20 чисел
    vector<NumSq> squares;  // тип данных вектора должен быть структурой
    for (int i = 1; i <= 20; i++) {
        int rn = rand() % 10;
        NumSq structure {rn, pow(rn, 2)};
        squares.push_back(structure);
    }
    sort(squares.begin(), squares.end(), my_comparison);  // отсортировать вектор от начала до конца по возрастанию
    for (auto ptr = squares.begin(); ptr != squares.end(); ptr++) {
        cout << ptr->number << "\n" << ptr->num_square << " ";
        cout << "\n\n";
    }
    return 0;
}