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

int main() {

    return 0;
}
