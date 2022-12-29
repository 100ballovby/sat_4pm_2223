#include <iostream>
#include <cstring>
using namespace std;

void hw_task_doule() {
    char str[100];
    cout << "Type: ";
    cin.getline(str, 100);

    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i]) && str[i + 1] == '.' && isdigit(str[i + 2])) {
            cout << str[i] << str[i + 1];
            int index = i + 2;
            while (isdigit(str[index])) {
                cout << str[index];
                index++;
            }
            cout << endl;
        }
    }
}