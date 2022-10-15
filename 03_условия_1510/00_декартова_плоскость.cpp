#include <iostream>
using namespace std;


int cascade() {
    /* Написать программу, которая получает два числа (х и у)
     * и определяет, к какой из четвертей декартовой
     * плоскости относится точка с этими координатами */
    int x, y;
    cout << "Insert x:";
    cin >> x;  // присвиваю значение с клавиатуры
    cout << "Insert y:";
    cin >> y;

    if (x > 0 && y > 0) {
        cout << 1 << endl;
    }
    else if (x < 0 && y > 0) {
        cout << 2 << endl;
    }
    else if (x < 0 && y < 0) {
        cout << 3 << endl;
    }
    else if (x > 0 && y < 0) {
        cout << 4 << endl;
    }
    else {
        cout << "on axle" << endl;
    }
    return 0;
}

// ################################################################################################

int included() {
    /* Написать программу, которая получает два числа (х и у)
     * и определяет, к какой из четвертей декартовой
     * плоскости относится точка с этими координатами */
    int x, y;
    cout << "Insert x:";
    cin >> x;  // присвиваю значение с клавиатуры
    cout << "Insert y:";
    cin >> y;

    if (y > 0) {
        if (x > 0) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
    else {
        if (x < 0) {
            cout << 3 << endl;
        }
        else {
            cout << 4 << endl;
        }
    }
    return 0;
}