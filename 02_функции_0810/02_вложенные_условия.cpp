#include <iostream>
using namespace std;


int w() {
    int a;
    cout << "Введи число: " << endl;
    cin >> a;

    if (a > 10) {
        if (a < 25) {
            cout << "число принадлежит промежутку [10;25]" << endl;
        }
        else {
            cout << "число не принадлежит промежутку [10;25]" << endl;
        }
    }

    return 0;
}