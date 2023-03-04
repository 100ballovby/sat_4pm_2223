#include <iostream>
#include <vector>
using namespace std;

void vector_basics() {
    // Нет необходимости указывать длину при иницилизации
    vector<int> v_array;
    v_array[0] = 7;  // можно присваивать элементы вектору через [] (без проверки диапазона)
    v_array.at(3) = 5;  // можно присваивать с проверкой диапазона

    /**В отличие от динамических массивов вектора сразу
     * высвобождают память, которая была им выделена. **/
}

void vector_length() {
    vector<int> v_array = {4, 5, 2};  // длина вектора - 3 элемента
    v_array.resize(10);  // изменяю длину вектора v_array ДО 10 элементов

    for (auto const &element: v_array) {
        cout << element << ' ';
    }

    cout << endl << "Length of vector is " << v_array.size() << " elements." << endl;

    // уменьшим длину вектора
    v_array.resize(2);  // изменяю длину вектора v_array до 2 элементов

    for (auto const &element: v_array) {
        cout << element << ' ';
    }

    cout << endl << "Length of vector is " << v_array.size() << " elements." << endl;
}

void vector_initializing() {
    vector<int> v_array;  // объявление вектора неопределенной длины 
    vector<float> v_array2 (5);  // объявление вектора длиной 5 элементов 
    vector<int> v_array3 (15, 2);  // объявление вектора длиной 15 элементов, каждый элемент - это двойка 

    // переберем второй вектор 
    for (int i = 0; i < v_array2.size(); i++) {
        cout << v_array2[i] << ' ';
    }

    cout << endl;
    // переберем третий вектор (у которого по умолчанию двойки)
    for (auto &element : v_array3) {
        cout << element << ' ';
    }
}