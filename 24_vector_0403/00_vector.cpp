#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

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

void vector_push_back() {
    // создаем вектор строк
    vector<string> students;
    // временное хранилище фамилий студентов
    string buffer;

    cout << "Insert students names. Insert empty string for exit: " << endl;
    do {
        getline(cin, buffer);  // получаю ввод от пользователя
        if (!buffer.empty()) {  // если нам ввели не пустую строку
            students.push_back(buffer);  // добавляем занчение в вектор
            // метод push_back(x) добавляет значение х в конец вектора
        }
    } while (buffer != "");  // проверяю: не пустой ли он

    unsigned int vector_size = students.size();// метод push_back(x) добавляет значение х в конец вектора

    // выведем заполненный вектор в консоль
    cout << "Students: " << endl;
    for (auto &student : students) {
        cout << student << endl;
    }
}

void vector_add_elements() {
    vector<int> numbers = {10, 8, 6, 4, 2, 1};

    numbers.emplace_back(8);  // этот метод тоже добавляет элемент в конец вектора
    print_vector(numbers);

    auto start = numbers.begin();
    // insert(position, value) - вставляет value на место position
    numbers.insert(start + 2, 17);
    /** begin() определяет место в памяти, где начинается вектор. Фиксирует позицию первого элемента,
     * мы добавляем к начальной позиции 2, чтобы указать, что работа с вектором начинается со второго
     * индекса (индекс первого (0) + 2 = 2)**/
    print_vector(numbers);

    // если передать insert 3 аргумента, вы сможете вставить опредленное количество элементов на место другого элемента
    numbers.insert(start + 3, 5, 10);  // на место элемента с индексом 3 вставить 5 десяток
    print_vector(numbers);
}

void vector_delete_element() {
    vector<int> numbers = {10, 8, 6, 4, 2, 1};
    // Удаление элементов вектора
    /**
     * - erase(ptr) - удаляет из вектора элемент, на который указывает ptr. После удаления элемента
     * ptr начинает указывать на элемент, который стоит следующим после удаленного или, если такого
     * элемента нет, то указывает на конец вектора.
     * **/

    auto start = numbers.begin();
    auto end = numbers.end();  // фиксирую точку в конце вектора
    numbers.erase(end - 1, end);  // удалить элемент с -1 (предпоследнего) до последнего
    print_vector(numbers);


    start = numbers.begin();
    end = numbers.end();  // фиксирую точку в конце вектора
    // хочу удалить с 3 индекса до 7
    numbers.erase(start + 2, end);  // удалить элемент с 3 до -1
    print_vector(numbers);
}

void vector_comparison() {
    vector<int> v1 {1, 2, 3};
    vector<int> v2 {1, 2, 3};
    vector<int> v3 {3, 2, 1};

    // вектора можно сравнивать между собой
    bool v1_equals_v2 = v1 == v2;  // true
    bool v1_equals_v3 = v1 != v3;  // true
    bool v2_equals_v3 = v2 == v3;  // false

    cout << "Vector v1 equals v2: " << v1_equals_v2 << endl;
    cout << "Vector v1 not equals v3: " << v1_equals_v3 << endl;
    cout << "Vector v2 equals v3: " << v2_equals_v3 << endl;
    /** при сравнении двух векторов операторами сравнения
     * происходит сравнение всех элементов вектора и, если
     * вектора содержат одни и те же элементы, вектора будут равны **/

    bool vector_are_equal = true;
    for (int i = 0; i < v1.size(); i++) {  // в подобном сравнении нет смысла, потому что вектора можно сравнивать обычными операторами
        if (v1[i] != v2[i]) {
            vector_are_equal = false;
            break;
        }
    }
    cout << "Vector v1 are equal v2: " << vector_are_equal << endl;
}
