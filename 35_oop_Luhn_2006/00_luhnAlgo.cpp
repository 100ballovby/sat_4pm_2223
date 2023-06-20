#include <iostream>
#include <string>
using namespace std;

class LuhnAlgorithm {
private:
    string cardNumber;
public:
    LuhnAlgorithm(string &number) : cardNumber(number) {}

    bool isValidCardNumber() {
        int sum = 0;
        bool alternate = false;

        // идем по номеру карту справа налево
        for (int i = cardNumber.length() - 1; i >= 0; i--) {
            int digit = cardNumber[i] - 'O';

            if (alternate) {
                digit *= 2;
                if (digit > 9) {
                    digit = (digit % 10) + 1;
                }
            }
            sum += digit;
            alternate = !alternate;
        }
        return (sum % 10 == 0);
    }
};

int mainLuhnAlgo() {
    string cardNumber;
    cout << "Insert bank card number: ";
    cin >> cardNumber;

    LuhnAlgorithm validator(cardNumber);
    bool isValid = validator.isValidCardNumber();
    switch (isValid) {
        case 1:
            cout << "Card number is valid" << endl;
            break;
        case 0:
            cout << "Card number not valid" << endl;
            break;
    }
    return 0;
}
