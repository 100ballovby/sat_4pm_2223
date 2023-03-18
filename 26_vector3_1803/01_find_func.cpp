#include <iostream>
#include <vector>
#include <algorithm>  // если не работает find
#include <string>
using namespace std;


void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void vector_linear_search() {
    vector<int> v { 5, 2, 12, 7, 9, -3, 16, 5 };
    auto start { v.begin() };
    auto end { v.end() };

    int key;
    cout << "Key: "; cin >> key;

    // найдем key в векторе
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            cout << i << endl;
            break;
        }
    }
    // найдем key в векторе через указатели
    for (auto ptr = start; ptr != end; ptr++) {
        if (*ptr == key) {
            cout << *ptr << endl;
            break;
        }
    }
}

void vector_linear_search_pointer() {
    vector<int> v { 5, 2, 12, 7, 9, -3, 16, 5 };
    auto start { v.begin() };
    auto end { v.end() };

    int key;
    cout << "key: "; cin >> key;
    // найдем key в векторе через указатели
    int found;
    for (auto ptr = start; ptr != end; ptr++) {
        if (*ptr == key) {
            found = *ptr;  // присваиваю значение указателя переменной found
            break;
        }
    }

    auto i_key = find(v.begin(), v.end(), found);
    cout << key << " in vector is " << i_key - v.begin() << "th index" << endl;
}

void function_find_arrays() {
    int myints[] = { 10, 20, 30, 40, 50 };
    int *p;  // указатель, значение которого будет добавляться функцией find()

    p = find(myints, myints + 5, 40);
    if (p != myints + 5) {  // если поиск не вышел за пределы массива
        cout << "Element found: " << p - myints << endl;
        // отнимаю от адреса найденного элемента начало массива
    } else {
        cout << "Elements is not found!" << endl;
    }
}