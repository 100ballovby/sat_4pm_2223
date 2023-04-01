#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

void add_empl(vector<Employee> &v) {
    int id = v.size() + 1;
    Employee empl;
    empl.id = id;
    cout << "Age: "; cin >> empl.age;
    cout << "Name: "; cin >> empl.name;
    cout << "Salary: "; cin >> empl.salary;

    v.push_back(empl);
}

void show_all_employees(vector<Employee> &v) {
    for (auto ptr = v.begin(); ptr != v.end(); ptr++) {
        cout << "ID: " << ptr->id << endl;
        cout << "Name: " << ptr->name << endl;
        cout << "Age: " << ptr->age << endl;
        cout << "Salary: " << ptr->salary << endl;

        cout << endl << endl;
    }
}

bool compare_by_salary(const Employee &e1, const Employee &e2) {
    return e1.salary > e2.salary;
}

int sv_main() {
    int choice;

    Employee james {1, 25, "James Doe", 1120.2};  // инициализация новой структуры
    Manager Ivan {{3, 38, "Ivan Dmitriev", 10000}, "IT"};

    vector<Employee> employees;  // создаю вектор с типом данных структуры

    employees.push_back(james);  // добавляю в вектор работника

    while (choice != 3) {
        cout << "Choose: \n1 - Add employee, \n2 - show all employees\n 3- exit";
        cin >> choice;

        if (choice == 1) {
            add_empl(employees);
        } else if (choice == 2) {
            sort(employees.begin(), employees.end(), compare_by_salary);
            cout << "List of employees: " << endl << endl;
            show_all_employees(employees);
        }
    }

    return 0;
}