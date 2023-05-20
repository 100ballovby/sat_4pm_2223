#include <iostream>
#include <string>
using namespace std;

class CaesarCipher {
private:
    int shift;
public:
    // Конструктор с параметрами
    CaesarCipher(int cipherShift) {
        shift = cipherShift;
    }

    // метод шифрования
    string encrypt(string &message) {
        string encryptedMessage = "";

        for (char c : message) {
            // проверим, является ли символ буквой
            if (isalpha(c)) {
                char base = islower(c) ? 'a' : 'A';
                int alphabetSize = 26;
                int alphabetIndex = (c - base + shift) % alphabetSize;
                if (alphabetIndex < 0) {
                    alphabetIndex += alphabetSize;
                }
                // преобразую символ обратно в букву
                char encrChar = base + alphabetIndex;
                encryptedMessage += encrChar;
            } else {
                encryptedMessage += c;
            }
        }
        return encryptedMessage;
    }

    string decrypt(string &encrMsg) {
        // для дешифровки будем использовать отрицательный сдвиг
        CaesarCipher decryptCipher(-shift);
        return decryptCipher.encrypt(encrMsg);
    }
};

int main() {
    int shift;
    string message;

    cout << "Insert message: ";
    getline(cin, message);

    cout << "Insert shift: ";
    cin >> shift;

    CaesarCipher cipher(shift);

    string encryptedMessage = cipher.encrypt(message);
    cout << "Encrypted: " << encryptedMessage << endl << endl;

    string decryptedMessage = cipher.decrypt(encryptedMessage);
    cout << "Decrypted: " << decryptedMessage << endl << endl;
    return 0;
}
