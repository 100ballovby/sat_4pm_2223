#include <iostream>
#include <string>  // "подключаю" строки к своему файлу
using namespace std;


void swap_letters() {
    /** Поменяйте местами первую и последнюю букву в слове **/
    string phrase;
    int length;  // длина строки
    cout << "Insert phrase: ";
    getline(cin, phrase);
    length = phrase.size();
    cout << phrase << endl;

    char tmp = phrase[0];  // сохраняю первую букву слова
    phrase[0] = phrase[length - 1];  // ставлю последнюю букву на место первой
    phrase[length - 1] = tmp;

    cout << phrase << endl;
}

void append_method() {
    string phrase = "abcd";
    string s2 = "123456789";
    /* Метод append() позволояет объединить две строки
     * - str.append(s, start) - к строке str добавятся символы строки s,
     * начиная с индекса start
     * - str.append(s, index, count) - к строке str добавятся символы строки
     * s, в количестве count начиная с индекса index
     */
    phrase.append(s2, 4);
    cout << phrase << endl;  // abcd56789
    phrase.append(s2, 1, 3);
    cout << phrase << endl;  // abcd56789234
}

void erase_method() {
    string phrase;
    string s2 = "123456789";
    cout << "Insert phrase: ";
    getline(cin, phrase);

    /* Метод .erase() позволяет удалить символы из строки
     * - str.erase() - удаляет ВСЕ символы из строки str;
     * - str.erase(index, num) - удаляет num символов из строки str,
     * начиная с индекса index
    */
    s2.erase();
    cout << s2 << endl;
    // phrase = "Hello, Andrew";
    phrase.erase(2, 4);  // He Andrew
    cout << phrase << endl;
}

void str_lab_task2() {
    string phrase;
    string s2 = "123456789";
    cout << "Insert phrase: ";
    getline(cin, phrase);

    /*Составить программу, которая во вводимой с клавиатуры строке
     * удаляет n элементов, начиная с k-го элемента. Где n и k —
     * вводимые с клавиатуры числа целого типа. Преобразованную
     * строку вывести на экран*/
    // вариант 1
    int n, k;
    cout << "Insert n and k:";
    cin >> n >> k;
    // здесь нужно написать числа через пробелы, тогда первое уйдет
    // в n, второе в k
    phrase.erase(k, n);
    cout << phrase << endl;
}

void str_lab_task3() {
    string phrase;
    cout << "Insert phrase: ";
    getline(cin, phrase);

    /* Ввести с клавиатуры строку. После каждого символа 'a' вставить пробел.
     * Преобразованную строку вывести на экран. */

    string new_phrase;  // сюда переместятся символы из переменной phrase
    for (int i = 0; i < phrase.size(); i++) {  // перебираем символы строки
        new_phrase += phrase[i];  // каждый символ строки добавляем в новую переменную
        if (phrase[i] == 'a') {  // если символ, который сейчас взяли - это буква a
            new_phrase += ' ';  // добавить в новую переменную (поставить после а) пробел
        }
    }
    cout << new_phrase << endl;
}

void str_lab_task4() {
    string phrase1 = "mama mila ramu gde mama?";
    string phrase2 = "mama mila ramu gde mama?";
    //  вариант 1
    if (phrase1 == phrase2) {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    // вариант 2
    bool alike = phrase1 == phrase2;  // строки сравниваются посимвольно (каждый с каждым)
    cout << alike << endl;

    // вариант 3
    bool like;  // результат проверки
    for (int i = 0; i < phrase1.size(); i++) {  // перебираю индексы по количеству элементов строки
        if (phrase1[i] == phrase2[i]) {  // если буква с индексом i совпадает у обеих строк
            like = true;  // в результат написать true
        } else {  // если встречаются две разные буквы
            like = false;  // в результат пишу false
            break;  // выхожу из цикла
        }
    }
    cout << like << endl;
}

void str_lab_task5() {
    /*Удалить из строки все символы '+'. Преобразованную
     * строку вывести на экран. */
    string phrase, new_phrase;
    cout << "Phrase: ";
    getline(cin, phrase);

    /* Для решения задачи, мы будем добавлять в new_phrase
     * все буквы из phrase, но если встретим +, добавлять
     * его не будем. */
    for (int i = 0; i < phrase.size(); i++) {
        if (phrase[i] != '+') {
            new_phrase += phrase[i];
        }
    }

    cout << new_phrase << endl;
}

void str_lab_task8() {
    /* Выяснить, верно ли, что среди символов
     * строки имеются все буквы, входящие
     * в слово 'father'. */
    string phrase, word;
    cout << "Phrase: ";
    getline(cin, phrase);
    word = "father";
    bool res = false;  // по умолчанию в строке нет букв из слова father

    for (int i = 0; i < word.size(); i++) {  // перебираю символы в слове father
        for (int j = 0; j < phrase.size(); j++) {  // перебираю символы в phrase
            if (phrase[j] == word[i]) {  // если символ i в word совпадает хотя бы с одним символом в phrase
                res = true;  // пишем true
                break;  // выходим из цикла, когда найдем первое совпадение
            } else {  // иначе пишем false
                res = false;
            }
        }
        if (!res) {  // если результат false (если хотя бы одна буква пропущена)
            break;  // выходим из цикла
        }
    }

    cout << res << endl;
}