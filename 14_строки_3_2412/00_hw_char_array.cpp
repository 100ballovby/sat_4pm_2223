#include <iostream>
#include <cstring>  // для работы strcpy и прочего
using namespace std;

void char_hw_t1() {
    // посчитать количество слов
    char phrase[100];
    cout << "Type smth: ";
    cin.getline(phrase, 100);
    int word_counter = 0;
    for (int i = 0; i < strlen(phrase); i++) {
        if (phrase[i] == ' ') {
            word_counter++;
        }
    }
    cout << "There is " << word_counter + 1 << " words" << endl;
}

void char_hw_t2() {
    // посчитать большие и маленькие буквы в строке
    char phrase[100];
    cout << "Type smth: ";
    cin.getline(phrase, 100);
    int big_letters = 0;
    int small_letters = 0;
    for (int i = 0; i < strlen(phrase); i++) {
        if (isupper(phrase[i])) {
            big_letters++;
        } else if (islower(phrase[i])) {
            small_letters++;
        }
    }
    cout << "There is " << big_letters << " upper letters" << endl;
    cout << "There is " << small_letters << " lower letters" << endl;
}

void char_hw_t3() {
    // посчитать названия городов
    char phrase[100];
    cout << "Type smth: ";
    cin.getline(phrase, 100);
    int cities = 0;
    for (int i = 0; i < strlen(phrase); i++) {
        if (isupper(phrase[i]) && phrase[i + 1] != '\'') {
            cities++;
        }
    }
    cout << "There is " << cities << " city names" << endl;
}