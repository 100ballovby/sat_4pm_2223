#include <iostream>
#include <string>  // "подключаю" строки к своему файлу
using namespace std;

void hw() {
    string phrase;
    cout << "Insert phrase: ";
    getline(cin, phrase);
    int count = 0;
    for (int i = 0; i < phrase.length(); i++) {
        if (phrase[i] == '.' || phrase[i] == ','
            || phrase[i] == '!' || phrase[i] == '?' ||
            phrase[i] == ';' || phrase[i] == ':') {
            count++;
        }
    }
    cout << "Prep: " << count << endl;
}