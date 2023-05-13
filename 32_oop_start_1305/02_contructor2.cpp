#include <iostream>
#include <cassert>
using namespace std;


class Fraction {
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(int numerator=0, int denominator = 1) { // конструктор с двумя параметрами
        assert(denominator != 0);  // проверяем, что знаменатель не равен 0
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};


int contructor2_main() {
    Fraction drob;  // так как мы не передаем никаких аргументов (потому что мы не можем), то вызывается конструктор по умолчанию
    cout << drob.getNumerator() << "/" << drob.getDenominator() << endl;

    // так как в конструкторе есть параметры (один из них по умолчанию), я могу при инициализации экземпляра сразу присвоить значения переменным-членам класса
    Fraction drob2 { 5, 12};
    Fraction drob3 { 10 };  // m_denominator = 1
    cout << drob2.getNumerator() << "/" << drob2.getDenominator() << endl;
    cout << drob3.getNumerator() << "/" << drob3.getDenominator() << endl;
    return 0;
}
