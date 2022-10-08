#include <iostream>
using namespace std;

// эта процедура не принимает аргментов
void print() {
    cout << "внутри функции print()" << endl;
}
// эта функция принимает 1 аргумент n
void printValue(int n) {
    cout << "Мне передали: " << n << endl;
}

int add(int a, int b) {
    /* При вызоове функции, все ее параметры создаются как
     * локальные переменные, а значение каждого аргумента
     * присваивается в соответсвующую переменную. Этот процесс
     * называется "передача по значению" */
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

int doubleNumber(int number) {
    return number * 2;
}