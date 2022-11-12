#include <iostream>
#include <cmath>
using namespace std;

void hw_task1() {
    // квадраты чисел
    int n;
    cout << "N: ";
    cin >> n;
    int square = 1;
    while (pow(square, 2) < n) {
        cout << pow(square, 2) << ", ";
        square++;
    }
    // через for
    for (int i = 1; pow(i, 2) < n; i++) {
        cout << pow(i, 2) << ", ";
    }
}

void hw_task2() {
    int n;
    cout << "N: ";
    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
            break;
        }
    }
}