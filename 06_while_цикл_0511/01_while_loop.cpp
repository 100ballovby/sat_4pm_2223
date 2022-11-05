#include <iostream>
#include <cmath>
using namespace std;

int randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}

void loop_while() {
    int i = 0;
    for (; i < 10;) {
        cout << i << ", ";
        i++;
    }
    cout << endl;

    int j = 0;  // счетчик цикла
    while (j <= 10) {  // объявление цикла
        cout << j << ", ";
        j+=3;  // инкремент
    }
}

void try_to_guess() {
    // написать программу "угадай число"
    int n, guess, attempts = 0;
    cout << "Try to guess my number! (from 1 to 100)" << endl;
    n = randint(1, 100);
    while (attempts < 7 && n != guess) {  // пока пользователь не угадал число или не потратил все попытки
        cout << "Guess: " << endl;
        cin >> guess;
        attempts++;  // увеличиваю количество попыток после ввода числа на 1
        if (guess > n) {
            cout << "My number is lower, than yours. Try again" << endl;
        } else if (guess < n) {
            cout << "My number is greater, than yours. Try again" << endl;
        }
    }

    if (n == guess) {
        cout << "Congratulations! For only " << attempts << " attempts!" << endl;
    } else {
        cout << "Sorry! My number is " << n << endl;
    }
}

void sum_of_digits() {
    // сумма цифр числа
    int n, summ;
    cout << "Insert n: ";
    cin >> n;
    summ = 0;
    while (n != 0) {
        summ += n % 10;  // достаю последнюю цифру числа и прибавляю к сумме
        n /= 10;  // отрезаю с каждым повторением последнюю цифру
    }
    cout << summ << endl;
}

void fibonacci() {
    srand(time(NULL));
    int n, summ, i = 0, i1 = 0, i2 = 1;
    cout << "N = ";
    cin >> n;
    while (i < n) {
        cout << i1 << endl;
        summ = i1 + i2;
        i++;
        i1 = i2;
        i2 = summ;
    }
}

void do_while() {
    int n = 12;
    // do...while - сначала делает, а потом думает (проверяет условие) 
    do {
        cout << "Hello!" << endl;  // будет совершено одно повторение до проверки условия 
        n++;
    } while (n <= 10);

    // while - сначала проверяет условие (думает), а потом делает 
}