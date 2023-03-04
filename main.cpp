#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
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
    return 0;
}