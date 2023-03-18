#include <iostream>
#include <vector>
#include <algorithm>  // если не работает find
#include <string>
using namespace std;


/**
 * Петя успевает по математике лучше всех в классе, поэтому
 * учитель задал ему сложное домашнее задание, в котором нужно в
 * заданном наборе целых чисел найти сумму всех положительных элементов,
 * затем найти где в заданной последовательности находятся максимальный
 * и минимальный элемент и вычислить произведение чисел, расположенных
 * в этой последовательности между ними. Так же известно, что
 * минимальный и максимальный элемент встречаются в заданном множестве
 * чисел только один раз и не являются соседними. Поскольку задач такого
 * рода учитель дал Пете около ста, то Петя как сильный программист
 * смог написать программу, которая по заданному набору чисел
 * самостоятельно находит решение. А Вам слабо?
 * **/

int task_p() {
    int maximum = 0, minimum = 0, sum = 0, mult = 1;
    vector<int> ints { -2, 19, -14, 4, 5, 12, 0, 11, -9, 2, 16, -3, -18 };
    auto start { ints.begin() };
    auto end { ints.end() };

    for (auto i { start }; i != end; i++) {
        /* так писать условия можно только в случае, если у вас один стейтмент */
        if (*i > maximum) maximum = *i;
        if (*i < minimum) minimum = *i;
        if (*i > 0) sum += *i;
        /* ******* */
    }
    cout << "Max: " << maximum << endl;
    cout << "Min: " << minimum << endl;
    cout << "Sum: " << sum << endl;

    // найду индексы элементов (максимального и минимального)
    auto i_max = find(ints.begin(), ints.end(), maximum);
    auto i_min = find(ints.begin(), ints.end(), minimum);
    int mult_s = i_max - ints.begin();
    int mult_f = i_min - ints.begin();

    cout << "Index of max: " << mult_s << endl;
    cout << "Index of min: " << mult_f << endl;

    // цикл будет выбирать, с какого элемента ему начинать работу, на основе значения, которое вернется от функций min и max
    for (int i = min(mult_s, mult_f) + 1; i < max(mult_s, mult_f); i++) {
        if (ints[i] != 0) mult *= ints[i];
    }

    cout << "Multiplication: " << mult << endl;

    return 0;
}