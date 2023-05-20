#include <iostream>
#include <string>
using namespace std;


class Student {
private:
    string name;
    int age;
    double averageGrade;
public:
    // Конструктор
    Student(string StudentName, int StudentAge, double Grade) {
        name = StudentName;
        age = StudentAge;
        averageGrade = Grade;
    }

    // сеттеры
    void setName(string StudentName) {
        name = StudentName;
    }

    void setAge(int StudentAge) {
        age = StudentAge;
    }

    void setAverageGrade(double grade) {
        averageGrade = grade;
    }

    // геттеры
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    double getAverageGrade() {
        return averageGrade;
    }
};

int hw_oop_main() {
    Student ivan("Ivan", 20, 5.6);

    // изменим данные
    ivan.setName("Petr");
    ivan.setAge(21);
    ivan.setAverageGrade(8.9);

    // получим данные
    cout << "имя: " << ivan.getName() << endl;
    cout << "возраст: " << ivan.getAge() << endl;
    cout << "Средний балл: " << ivan.getAverageGrade() << endl;
    return 0;
}
