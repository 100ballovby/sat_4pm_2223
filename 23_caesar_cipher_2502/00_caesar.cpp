#include <iostream>
#include <string>

using namespace std;

string caesar_cipher(string phrase, int shift, string lang) {
    string eng = "abcdefghijklmnopqrstuvwxyz";
    string rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string alphabet = "";
    string res = "";  // зашифрованную строчку буду хранить здесь

    if (tolower(lang[0]) == 'r') {
        alphabet = rus;
    } else {
        alphabet = eng;
    }

    for (int i = 0; i < phrase.length(); i++) {
        int place = alphabet.find(phrase[i]);  // определяем индекс буквы в алфавите
        int new_place = place + shift;  // сохраняем новую позицию буквы в алфавите

        if (new_place >= alphabet.length()) {
            new_place -= alphabet.length();
        }

        if (ispunct(phrase[i]) || isspace(phrase[i])) {
            res += phrase[i];  // не меняю символ, если он является знаком препинания
        } else {
            res += alphabet[new_place];  // подставляю букву со сдвигом в строку
        }
    }
    return res;
}

void decipher(string phrase, string lang) {
    string eng = "abcdefghijklmnopqrstuvwxyz";
    string rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    string alphabet = "";
    int shift = 0;  // изначальный сдвиг

    if (tolower(lang[0]) == 'r') {
        alphabet = rus;
    } else {
        alphabet = eng;
    }

    while (shift < alphabet.length()) {
        string res = "";
        for (int i = 0; i < phrase.length(); i++) {
            int place = alphabet.find(phrase[i]);
            int new_place = place - shift;

            if (new_place <= 0) {
                new_place += alphabet.length();
            }

            if (ispunct(phrase[i]) || isspace(phrase[i])) {
                res += phrase[i];
            } else {
                res += alphabet[new_place];
            }
        }
        cout << "Shift " << shift << " - " << res << endl;
        shift++;
    }
}

int zapusk() {
    cout << caesar_cipher("how are you", 4, "eng") << endl;
    decipher("lsa evi csy", "eng");
    return 0;
}