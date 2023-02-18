#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int menu() {
    cout << "Please, choose option: \n";
    cout << "0 - exit\n1 - Register\n2 - Login\n\n";
    int ans;
    cin >> ans;
    return ans;
}

bool isLoggedIn(string username, string password) {  // функция, которая будет проверять, вошел ли пользователь в систему
    string uname, passw;  // сюда будем сохранять данные пользователя из файла
    ifstream read("../data/" + username + ".txt");  // открываю файл с названием username.txt из папки data
    getline(read, uname);  // считываю username и присваиваю его переменной uname
    getline(read, passw);  // считываю password и присваиваю его переменной passw

    read.close();  // закрываем файл после работы

    if (uname == username && passw == password) {  // если данные от пользователя совпадают с данными из файла
        return true;
    } else {
        return false;
    }
}

bool userRegister(string username, string password, string confirmation) {
    if (password == confirmation) {
        ofstream file;
        file.open("../data/" + username + ".txt", ios::out);
        file << username << endl << password;
        file.close();
        return true;
    } else {
        return false;
    }
}

// переберем названия файлов в папке data


int main() {
    int option = 3;
    while (option != 0) {
        option = menu();

        if (option == 1) {
            string login, password, confirm;
            cout << "Login: "; cin >> login;
            cout << "Password: "; cin >> password;
            cout << "Password (again): "; cin >> confirm;

            bool status = userRegister(login, password, confirm);

            if (status) {  // if (status == true)
                cout << "Successfully registration!\n\n";
            } else {
                cout << "Passwords aren't math, try again!\n\n";
            }
        } else if (option == 2) {
            string login, password;
            cout << "Your login (username): "; cin >> login;
            cout << "Your password: "; cin >> password;
            bool status = isLoggedIn(login, password);

            if (status) {  // if (status == true)
                cout << "Successfully logged in!\n\n";
            } else {
                cout << "Login or/and password is incorrect!\n\n";
            }
        }
    }

    return 0;
}