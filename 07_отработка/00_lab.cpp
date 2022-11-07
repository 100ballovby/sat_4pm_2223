#include <iostream>
using namespace std;

void for_base() {
    int c = 7;
    int i = 1;  // переменная цикла
    for (; i <= c;) {  // объявление и условие работы цикла
        // неучтенная единица (иногда используйте <=/>= чтобы получить последовательность включительно stop
        cout << i << endl;
        i += 2;  // инкремент
    }
}

void sum_for() {
    int c = 7;
    int i = 1;
    int summ = 0;  // с нулем удобно складывать
    for (; i <= c;) {
        cout << i << endl;
        summ += i;  // результат = summ + i
        i++;
    }
    cout << summ << endl;
}

void factorial_for() {
    int c = 6;
    int i = 1;
    int factorial = 1;  // умножать на единицу так же удобно, как складывать с 0
    for (; i <= c;) {
        c *= i;  // результат = factorial * i
        i++;
    }
    cout << c << "! = " << c << endl;
}

void summ_of_factorials() {
    // посчитать сумму факториалов
    int summ_factorial = 0;
    for (int j = 1; j <= 10; j++) {  // внешний обеспечивает последовательность факториалов
        int factorial = 1;
        for (int i = 1; i <= j; i++) {  // внутренний цикл считает факториалы чисел в j
            factorial *= i;  // результат = factorial * i
        }
        cout << j << "! = " << factorial << endl;
        summ_factorial += factorial;  // суммирую получившийся факториал
    }
    cout << summ_factorial << endl;
}

void different_for() {
    // найти элемент, который делится на 7
    int arr[] = {3, 4, 9, 12, 67, 21, -8};
    for (int i = 0; i < 7; i++) {  // перебираю индексы массива
        if (arr[i] % 7 == 0) {
            cout << "Index: " << i << endl;
        }
    }
    for (int num : arr) {  // перебираю элементы массива (без индексов)
        if (num % 7 == 0) {
            cout << "Element: " << num << endl;
        }
    }
}

void run_task() {
    /* В первый день спортсмен пробежал x километров,
     * а затем он каждый день увеличивал пробег на 10% от
     * предыдущего значения. По данному числу Y определите
     * номер дня, на который пробег спортсмена составит
     * не менее Y километров. */
    double x, y;
    int days;
    x = 5.0;  // в первый день пробежал 5 километров
    y = 10.0;  // нужно пробежать 24 километра
    days = 0;
    while (x <= y) {
        x *= 1.1; // каждый день на 10% увеличивал пробег
        days++;
    }
    cout << days << endl;
}

void mult_with_zero() {
    /* В массиве целых чисел посчитать произведение элементов.
     * Если один из элементов массива является нулем, необходимо
     * остановить счет. */
    int x[] = {4, 1, 2, 7, 10, 3, -5, 0, 12, 4};
    int mult, i;
    mult = 1;  // произведение
    i = 0;  // индексы массива
    while (x[i] != 0) {  // пока конкретный элемент массива не ноль
        mult *= x[i];
        i++;
    }
    cout << mult << endl;

    // вариант решения через for
    mult = 1;
    for (int j = 0; j < 10; j++) {
        if (x[j] == 0) {
            break;
        } else {
            mult *= x[j];
        }
    }
    cout << mult << endl;
}

void payment() {
    /* Пользователь хочет пополнить карточку через банкомат,
     * он вводит сумму с клавиатуры, предусмотреть в программе
     * возможность изменения ошибочно введенной суммы. */
    double payment = 0;
    int exit = 0;
    do {
        cout << "Insert summ: ";
        cin >> payment;
        cout << "Change summ - 1, exit - 0";
        cin >> exit;
    } while (exit == 1);
}