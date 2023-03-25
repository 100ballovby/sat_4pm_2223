#include <iostream>
#include <string>
using namespace std;

struct Employee {
    short int id;  // поле структуры id
    int age;
    string name;
    double salary;
};  // это структура

struct Manager {
    Employee CEO;  // все поля из структуры Employee мы добавляем в Manager
    string department;  // добавляю новое поле в структуру
};

void printInfo(Employee *human) {
    cout << "ID: " << human->id << endl;  // при передаче структуры через ссылку, нужно обращаться через ->, в других ситуациях через .
    cout << "Age: " << human->age << endl;
    cout << "Name: " << human->name << endl;
    cout << "Salary: " << human->salary << endl;
}

int glavniy_file() {
    Employee john;  // имя структуры - тип данных, john - имя переменной
    john.id = 1;  // присваивание значения полю структуры
    john.age = 27;
    john.name = "John Doe";
    john.salary = 1023.55;

    Employee james {2, 25, "James Doe", 1120.2};  // инициализация новой структуры

    cout << "John " << john.age << " years old." << endl;
    cout << "James " << james.age << " years old." << endl;

    int totalAge = john.age + james.age;
    if (john.salary > james.salary) {
        cout << "John makes more than James\n";
    } else if (john.salary < james.salary) {
        cout << "James makes more than John\n";
    } else {
        cout << "John and James make the same amount\n";
    }

    // James получил прибавку к зарплате
    james.salary += 500;

    // у Джона ДР
    john.age++;

    printInfo(&john);

    Manager Ivan {{3, 38, "Ivan Dmitriev", 10000}, "IT"};
    cout << "Manager: " << Ivan.CEO.name << ", department " << Ivan.department << endl;
    return 0;
}