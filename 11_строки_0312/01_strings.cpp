#include <iostream>
#include <string>  // "подключаю" строки к своему файлу
using namespace std;


void string_basics() {
    string s1 = "Hello!";  // инициализировал строчную переменную со значением hello
    string s2;  // пустая строчка
    string s3(5, 'f');
    /* если нужно, чтобы строка содержала определенное
     * количество символов, напишите количество и сам символ */

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
}

void operations_strings() {
    string s1 = "Hello!";  // инициализировал строчную переменную со значением hello
    string s2;  // пустая строчка
    string s3(5, 'f');  // не совсем умножение строк
    /* если нужно, чтобы строка содержала определенное
     * количество символов, напишите количество и сам символ */

    cout << s1 << endl;
    // конкатенация - сложение строк
    cout << s1 + " How are you?" << endl;

    // сравнение через знаки >\< происходит по
    // позициям букв в алфавите
    bool res = "elephant" < "mouse";
    cout << res << endl;

    string email1 = "greatraksin@icloud.com";
    string email2 = "GreatRaksin@iCloud.com";
    bool res1 = email1 == email2;
    // при сравнении через ==/!= сравниваются
    // не позиции в алфавите, а индексы из таблицы ASCII
    cout << res1 << endl;

}

void string_loops() {
    string s2;
    string phrase = "Hello, Andrew!";
    // у строк есть индексы
    cout << phrase[5] << endl;  // обращение к элементам по индексу такое же, как у массивов
    // замена элемента в строке
    phrase[1] = 'a';  // элементы строки можно заменять, обратившись по индексу
    cout << phrase << endl;

    // перебор строки
    cout << phrase.length() << endl;
    for (int i = 0; i < phrase.length(); i++) {
        cout << phrase[i] << " ";
    }
    // .length() - возвращает целочисленное значение = количеству символов в строке
    cout << endl;
    // проверка пустоты строки
    if (s2.empty()) {  // .empty() возвращает логический ответ "есть ли в строке символы"
        cout << "Строка пустая!" << endl;
    }
}

void string_and_cin() {
    string name;
    string full_name;

    cout << "What is your name? ";
    cin >> name;
    cout << "Name: " << name << endl;

    /* cin считает, что в переменную нужно записать значение ДО
     * пробела, а все остальное игнорируется */
    cout << "What is your full name? ";
    // cin >> full_name;  // значение после пробела будет проигнорировано
    /* если до getline был cin, нужно написать следующее:  */
    cin.ignore(32767, '\n'); // проигнорировать символ новой строки
    getline(cin, full_name);  // читает всю строку (с пробелами) и при помощи "усмиренного" cin записывает все в переменную
    cout << "Full name: " << full_name << endl;
}

void count_words() {
    string sentence;
    cout << "Insert something: ";
    getline(cin, sentence);
    sentence += ' ';  // добавляю пробел, потому что слова разделяются пробелами
    int words = 0;
    // перебираю строчку
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' ') {
            words++;
        }
    }
    cout << "there is " << words << " words." << endl;
}

void transfer_letters() {
    // поменять местами первую и последнюю буквы в слове
    string letters = "horizontal"; // lorizontah
    char first = letters[0];
    char last = letters[letters.length() - 1];
    letters[0] = last;
    letters[letters.length() - 1] = first;
    cout << letters << endl;
}

void char_array() {
    char word[] = {'h', 'e', 'l', 'l', 'o', '!'};
    // массив символов
    char word1[] = {"hello!"};  // инициализировать массив символов можно так

    for (int i = 0; i < 6; i++) {
        cout << "word[" << i << "] = " << word[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < 6; i++) {
        cout << "word1[" << i << "] = " << word1[i] << endl;
    }
}