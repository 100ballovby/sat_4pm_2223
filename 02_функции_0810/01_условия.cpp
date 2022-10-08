#include <iostream>
using namespace std;

void c() {
    int a;
    cout << "Введи число: " << endl;
    cin >> a;

    if (a > 30) {  // если введенное пользователем число больше 30
        cout << a << " больше 30" << endl;
    } else if (a < 30) {  // иначе если (вторая проверка) число меньше 30
        cout << a << " меньше 30" << endl;
    } else {  // иначе (если введенное число равно 30)
        cout << a << " равно 30" << endl;
    }
}