#include <iostream>
#include <string>
#include <vector>
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

class Group {
private:
    vector<Student> students;
public:
    void addStudent(Student &student) {
        students.push_back(student);
    }

    void printGroupInfo() {
        for (auto &student : students) {
            cout << "Name: " << student.getName() << endl;
            cout << "Age: " << student.getAge() << endl;
            cout << "Average grade: " << student.getAverageGrade() << endl << endl;
        }
    }

    double calculateAverageGrade() {
        double sum = 0.0;
        int count = 0;  // считаем студентов
        for (auto &student : students) {
            sum += student.getAverageGrade();
            count++;
        }
        return sum / count;
    }
};

int student_is_main() {
    Group group_a;

    // создадим студентов
    Student student1 ("John", 20, 4.5);
    Student student2 ("Jane", 22, 4.2);
    Student student3 ("July", 19, 4.8);

    // Добавляем студентов в группу
    group_a.addStudent(student1);
    group_a.addStudent(student2);
    group_a.addStudent(student3);

    // выводим информацию о студентах
    cout << "Info about students: " << endl;
    group_a.printGroupInfo();

    // посчитаем средний балл
    double groupAverage = group_a.calculateAverageGrade();
    cout << "\nAverage grade of group 'A': " << groupAverage << endl;


    return 0;
}
