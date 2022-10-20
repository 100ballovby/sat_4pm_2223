#include <iostream>
using namespace std;


int th() {
    int a, b;
    cout << "Insert a:";
    cin >> a;
    cout << "Insert b:";
    cin >> b;

    if (a == 30) {
        cout << 1 << endl;
    }
    else if (b == 30) {
        cout << 2 << endl;
    }
    else if (a + b == 30) {
        cout << 3 << endl;
    }
    else {
        cout << "Null" << endl;
    }
    return 0;
}