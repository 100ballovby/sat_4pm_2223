#include <iostream>
using namespace std;


int n51() {
    /* вводится число n. Если n больше константны 51,
     * вывести абсолютную разницу (без знака) умноженную на три,
     * если n меньше 51, вывести абсолютную разницу */
    int n;
    const int x = 51;  // неизменямая переменная

    cout << "Insert n:";
    cin >> n;

    if (n > x) {
        cout << (n - x) * 3 << endl;
    }
    else {
        cout << x - n << endl;
    }
    return 0;
}