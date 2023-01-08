#include <iostream>
#include <string>
using namespace std;


int power(int n, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= n;
    }
    return res;  // вернуть фактическое значение переменной res
}

string change_even(string str) {
    for (int i = 0; i < str.length(); i+=2) {
        if (str[i] == 'a' || str[i] == 'b') {
            str[i] = 'c';
        } else {
            str[i] = 'a';
        }
    }
    return str;
}

void main_dlya_zadachi_pro_simvoli() {
    string phrase;
    cout << "String: ";
    getline(cin, phrase);
    cout << change_even(phrase) << endl;
}