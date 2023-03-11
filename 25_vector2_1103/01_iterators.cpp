#include <iostream>
#include <vector>
using namespace std;


void iterators() {
    vector<float> data{ 1.5, 2.3, -9.78, 1.112, 5.1, 3.21 };
    auto start { &data[0] };  // создали указатель на первый элемент контейнера data
    auto end { start + data.size() };  // указатель конца вектора - это указатель на место, следующее за последним элементом

    // итератор, когда бегает по контейнеру, предоставляет доступ к элементам
    for (auto i{ start }; i != end; i++) {
        cout << *i << ' ';
    }
}

void iterators_std() {
    vector<float> data{ 1.5, 2.3, -9.78, 1.112, 5.1, 3.21 };
    auto start { data.begin() };  // итератор из std:: (начало)
    auto end { data.end() };  // итератор из std:: (конец)

    // итератор, когда бегает по контейнеру, предоставляет доступ к элементам
    for (auto i{ start }; i != end; i++) {
        cout << *i << ' ';
    }
    cout << endl;
    for (float i : data) {  // явное указание диапазона
        // цикл незаметно обращается к функциям begin и end для осуществления работы
        cout << i << ' ';
    }
}
