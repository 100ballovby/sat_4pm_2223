#include <iostream>
#include <cstring>  // для работы strcpy и прочего
//#include <windows.h>
using namespace std;

void char_base() {
    char ch1;  // объявляю переменную типа char
    cout << "Insert symbol: ";
    cin >> ch1;  // так как char хранит ровно 1 символ, ни о каких getline речи не идет
    cout << ch1 << endl;
    // char можно складывать с char
    cout << ch1 + 'k' << endl;  // при сложении char складываются числовые коды символов из ASCII
}

void char_symbols() {
    char ch1 = 'o';  // инициализирую переменную char со значением 'o' (111)
    char ch2 = 107;  // инициализирую переменную char с числовым значением 107 ('k')

    cout << ch1 << endl;
    cout << ch2 << endl;

    // когда вы инициализируете переменные типа char с числовыми значениеми,
    // в них будет храниться символ, который сооветствует этому числу в таблице ASCII
    char ch3 = 0;
    // когда вы инициализируете переменные типа char с символьным значением
    // в них будет храниться тот же символ
    char ch4 = '0';
    cout << ch3 << endl;
    cout << ch4 << endl;
}

void char_static_cast() {
    char ch1 = 'o';  // инициализирую переменную char со значением 'o' (111)
    char ch2 = 107;  // инициализирую переменную char с числовым значением 107 ('k')

    int o_symb = ch1;  // так лучше не делать
    /* Оператор static cast позволяет изменить (конвертировать) тип данных
     * переменной в другой тип данных.
     * Синтаксис: static_cast<новый_тип_данных>(переменная) */
    cout << ch1 << endl;
    cout << ch2 << endl;
    cout << "Прямое преобразование: " << o_symb << endl;
    cout << "Преобразование static cast: " << static_cast<int>(ch1) << endl;
}

void transition() {
    char s1;
    cout << "Insert symbol: ";
    cin >> s1;
    cout << "In ASCII:" << static_cast<int>(s1) << endl;

    int n;
    cout << "Insert number from 0 to 127: ";
    cin >> n;
    cout << "Literal is: " << static_cast<char>(n) << endl;
}

void char_arrays_base() {
    // char array[10] = {'l', 'o', 'x'};  <- плохой способ инициализации
    char array[10] = "lox";  // <- хороший способ инициализации
    int array1[10] = {3, 4, 5};

    cout << array1 << endl;  // вывести целочисленный массив на консоль нельзя
    cout << array << endl;
    cout << strlen(array) << endl;  // <- измерение количества заполненных символов символьного массива
    for (int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
    /* Если в символьный массив записать количество символов меньше
     * указанной длины, остальные значения будут заполнены   */
}

void char_array_filling() {
    char string[100], symbol;
    int i = 0;

    // вариант 1 - наполнение символьного массива с клавиатуры
    cout << "Type text, finish with Enter: ";
    while (symbol != '\n') {
        symbol = getchar();  // функция getchar позволяет забрать символ с клавиатуры
        string[i] = symbol;
        i++;
    }
    cout << string << endl;

    // Вариант 2 - наполнение символьного массива с клавиатуры
    char string2[100];  // строковый массив
    cout << "Type text, finish with Enter: " << endl;
    gets(string2);  // функция gets считывает все символы (с пробелами) до нажатия на Enter
    cout << string2 << endl;
}

void special_functions() {

    char s1[100] = "I love Minecraft!";
    char s2[100];
    // копировать содержимое строчного массива
    strcpy(s2, s1);  // скопировать все из переменной s1 в переменную s2
    cout << s2 << endl;

    // сложение (конкатенация) символьных массивов
    cout << strcat(s1, " This is my life!") << endl;
    // strcat(s, s1) - складывает строку s со строкой s1

    // Функции проверки символов
    char symbol = 'a';  // буква
    char digit = '5';  // цифра
    char space = ' ';  // пробел
    char character = '#';  // знак

    cout << symbol << " - is it letter? ";
    isalpha(symbol) ? cout << "true\n" : cout << "false\n";  // тернарный оператор
    /* if (isalpha(symbol)) {
        cout << "true" << endl;
     } else {
        cout << "false" << endl;
     }
     * */
    cout << digit << " - is it digit? ";
    isdigit(digit) ? cout << "true\n" : cout << "false\n";

    cout << space << " - is it space? ";
    isspace(space) ? cout << "true\n" : cout << "false\n";

    cout << character << " - is it character? ";
    ispunct(character) ? cout << "true\n" : cout << "false\n";
}

void home_work_var2() {
    string phrase;
    cout << "Insert phrase: ";
    getline(cin, phrase);
    int count = 0;
    for (int i = 0; i < phrase.length(); i++) {
        if (ispunct(phrase[i])) {
            count++;
        }
    }
    cout << "Prep: " << count << endl;
}

int main() {
    //SetConsoleOutputCP(CP_UTF8);
    // Функции проверки символов
    char symbol = 'a';  // буква
    char digit = '5';  // цифра
    char space = ' ';  // пробел
    char character = '#';  // знак

    cout << symbol << " - is it letter? ";
    isalpha(symbol) ? cout << "true\n" : cout << "false\n";  // тернарный оператор
    /* if (isalpha(symbol)) {
        cout << "true" << endl;
     } else {
        cout << "false" << endl;
     }
     * */
    cout << digit << " - is it digit? ";
    isdigit(digit) ? cout << "true\n" : cout << "false\n";

    cout << space << " - is it space? ";
    isspace(space) ? cout << "true\n" : cout << "false\n";

    cout << character << " - is it character? ";
    ispunct(character) ? cout << "true\n" : cout << "false\n";

    char big_letter = 'B';
    char small_letter = 'b';
    cout << big_letter << " - is it uppercase? ";
    isupper(big_letter) ? cout << "true\n" : cout << "false\n";
    cout << small_letter << " - is it lowercase? ";
    islower(small_letter) ? cout << "true\n" : cout << "false\n";
    return 0;
}