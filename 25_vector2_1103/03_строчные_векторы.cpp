#include <iostream>
#include <vector>
#include <string>
using namespace std;

void change_string_vector() {
    // заменить первые буквы слов в векторе !
    vector<string> colors { "red", "green", "blue", "yellow", "pink", "purple", "white" };
    auto start { colors.begin() };  // итератор из std:: (начало)
    auto end { colors.end() };  // итератор из std:: (конец)

    for (auto ptr{ start }; ptr != end; ptr++) {
        cout << ptr->at(0) << " ";  // если вы работаете с указателем, обращение через . [] и прочее невозможны, нужно использовать ->
        // at(index) - возвращает элемент, находящийся на позиции index
        ptr->at(0) = '!';  // заменяю первую букву
    }

    for (auto c : colors) {
        cout << c << endl;
    }
}

void change_string_vector_index() {
    // заменить первые буквы слов в векторе !, но использовать обращение через индексы
    vector<string> colors { "red", "green", "blue", "yellow", "pink", "purple", "white" };

    for (int ptr = 0; ptr < colors.size(); ptr++) {
        colors[ptr][0] = '!';  // заменяю первую букву
    }

    for (auto c : colors) {
        cout << c << endl;
    }
}