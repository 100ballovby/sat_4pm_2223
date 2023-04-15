#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/* Создайте структуру BankAccount с модификатором
 * доступа private, содержащую поля account_number и balance.
 * Добавьте в нее методы deposit() и withdraw(), которые изменяют
 * баланс на определенную сумму. Метод deposit() должен
 * иметь модификатор доступа public, а метод withdraw()
 * должен иметь модификатор доступа private. Если сумма,
 * запрошенная для снятия, превышает баланс на счете,
 * метод withdraw() должен выводить сообщение об
 * ошибке и не изменять баланс. */
struct BankAccount {
private:
    int account_number;
    int balance;

    bool withdraw(int amount) {
        if (amount > balance) {
            cout << "Not enough funds!" << endl;
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

public:
    void deposit(int amount) {
        balance += amount;
    }

    int getBalance() {
        return balance;
    }
};

int main() {
    BankAccount account;
    int balance = account.getBalance();
    account.deposit(100);
    cout << "Current balance: " << balance << endl;
    return 0;
}