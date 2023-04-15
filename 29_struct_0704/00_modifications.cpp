#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Модификаторы доступа необходимы для сокрытия от внешнего воздействия данных структуры/класса
 * private - элемент (метод) не будет доступен любым экземплярам других структур или методов, которые не являются дружественными;
 * элемент не будет доступен из унаследованных структур; элемент не доступен из методов, которые реализованы в этой структуре (классе)
 *
 * protected - элемент (поле/метод) не доступен из внешнего метода, если этот метод не является дружественным
 * элемент доступен из внутренних методов структуры (класса); элемент будет доступен из методов унаследованной структуры (класса)
 *
 * public - элемент будет доступен всем методам, классам, структурам в программе.
 *
 * Если в структуре или классе изначально не указаны модификаторы доступа к данным, они по умолчанию
 * считаются public
 * **/

struct Book {
    char title[100];
    char author[100];
    int year;
    double price;

    // создадим метод (функцию) для структуры
    void print() {
        cout << "title: " << title << endl;
        cout << "author: " << author << endl;
        cout << "year: " << year << endl;
        cout << "price: " << price << endl;
    } // метод - это обычная функция, но доступна она ТОЛЬКО из структуры. Обратиться к методы вне структуры нельзя
};

// cоздадим структуру, которая содержит все необходимое для решения квадратных уравнений
struct SquareEquition {
    /** Структура сохраняет значение внутренних полей a,b,c;\n
     * Структура содержит методы доступа к a, b, c;\n
     * Структура выводит информацию о решении квадратного уравнения в удобной для чтения форме.\n\n
     *
     * Реализация структуры\n
     * 1. Скрытые (private) внутренние поля a, b, c, которые являются коэффициентами уравнения;\n
     * 2. Конструктор с тремя параметрами, которые соответствуют коэффициентам уравнения;\n
     * 3. Общедоступный (public) метод solve(), который занимается решением квадратного уравнения;\n
     * 4. Общедоступный (public) метод show_solution(), который выводит решение квадратного уравнения на консоль;\n
     * 5. Методы GetABC() и SetABC() для доступа к внутренним полям a, b, c;
     * **/
private:  // закрываем доступ к полям a, b, c
    double a, b, c;
public:
    // конструктор структуры
    SquareEquition(double coef_a, double coef_b, double coef_c) {
        // когда создается экземпляр структуры (коэффициентам ЭТОГО уравнения присваиваются значения)
        this->a = coef_a;
        this->b = coef_b;
        this->c = coef_c;
    }
    // методы доступа
    void getABC(double &a, double &b, double &c) {  // мы будем выводить значения ПРИВАТНЫХ полей, поэтому значения дергаем из структуры
        a = this->a;
        b = this->b;
        c = this->c;
    }
    void setABC(double coef_a, double coef_b, double coef_c) {  // мы будем устанвливать значение ПРИВАТНЫХ полей, поэтому экземпляру присваием те поля, что были указаны методу как параметры
        this->a = coef_a;
        this->b = coef_b;
        this->c = coef_c;
    }
    // метод solve() возвращает true, если уравнение имеет решение или false, если не имеет
    bool solve(double &x1, double &x2) {
        // вычисляем дискриминант
        double d = b * b - 4 * a * c;

        // проверка корней уравнения
        if (d < 0) {
            x1 = x2 = 0;
            return false;
        }
        // мы не доходим до вычисления корней, если дискриминант равен 0
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);
        return true;
    }

    // Метод выводит решение квадратного уравнения, данный метод будет обращаться к solve() для получения корней
    void show_solution() {
        double x1, x2;
        cout << "The equation: ";

        if (a != 0) {
            cout << a << "*a";
        }
        if (b != 0) {
            if (b > 0) {
                cout << " + ";
            }
            cout << b << "*b";
        }
        if (c != 0) {
            if (c > 0) {
                cout << " + ";
            }
            cout << c << "*c";
        }
        cout << " = 0";

        if (solve(x1, x2)) {  // есть ли решение уравнения?
            cout << "\nhas the following roots:\n";
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else {
            cout << "\nhas no roots:\n";
        }
    }
};

struct Person {
private:
    string name;
    int age;
    char gender;

public:
    void print_info() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

    void set_name(string n) {  // сеттер - метод, который может общаться с приватными полями
        this->name = n;
    }

    void set_age(int a) {  // сеттер - метод, который может общаться с приватными полями
        this->age = a;
    }

    void set_gender(char g) {  // сеттер - метод, который может общаться с приватными полями
        this->gender = g;
    }
};


int zap_mod() {
    Book b {"alice in wonderland", "rjfkjlwke", 2000, 100};
    int size = sizeof(b);

    // Решим квадратное уравнение
    SquareEquition e(3, -14, -5); // вызов конструктора
    e.setABC(6, -5, 3);
    e.show_solution();


    vector<SquareEquition> eqs {{3, -14, -5}, {5, -14, 17}, {-7, -13, 8}, {1, -3, -4}};
    auto start = eqs.begin();
    auto end = eqs.end();

    for (auto it = eqs.begin(); it != end; it++) {
        it->show_solution();
    }

    Person alice;
    alice.set_name("alice");
    alice.set_age(20);
    alice.set_gender('F');
    alice.print_info();
    alice.set_gender('M');
    cout << endl;
    alice.print_info();
    alice.set_name("Andrew");
    cout << endl;
    alice.print_info();
    return 0;
}