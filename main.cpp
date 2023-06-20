#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    double salary;
public:
    Person(string name, int age, double salary) : name(name), age(age), salary(salary) {}

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: $" << salary << endl;
    }

    void setSalary(double newSalary) {
        if (newSalary >= 0) {
            salary = newSalary;
            cout << "Salary changed." << endl;
        } else {
            cout << "Incorrect salary." << endl;
        }
    }
};

int main() {
    Person person("John", 30, 5000.0);

    person.displayInfo();
    person.setSalary(5500.0);
    person.displayInfo();
    return 0;
}
