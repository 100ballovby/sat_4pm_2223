#include <iostream>
using namespace std;


struct DateStruct {  // структуры используются в тех случаях, когда нужно просто хранить данные
    int day;
    int month;
    int year;
};


class DateClass {  // имена классов ВСЕГДА пишутся с БОЛЬШОЙ буквы
// данные класса по умолчанию должны быть сокрыты (есть исключения)
    // данные класса (это то, что будет в себе хранить экземпляр)
    int m_day;  // префикс m_ используется для того, чтобы вы могли более явно отделить данные класса от обычных переменных
    int m_month;  // m_ - member
    int m_year;

public: // в классах все данные являются по умолчанию сокрытыми от внешнего воздействия
    void setDate(int day, int month, int year) {  // метор-сеттер (метод, который может присваивать значения данным класса)
        if (day > 0 && day <= 31) {
            m_day = day;
        }
        if (month > 0 && month <= 12) {
            m_month = month;
        }
        m_year = year;
    }

    void getDate() {  // метод-геттер (функция) класса - поведение экземпляра, который вы будете создавать
        cout << m_day << "/" << m_month << "/" << m_year << endl;
    }
};


int classes_main() {
    DateStruct today { 13, 5, 2023 };
    DateClass tomorrow;  // экземпляр - это конкретная сущность, которая была построена на основе шаблона
    DateClass day_after_tomorrow;

    tomorrow.setDate(14, 5, 2023);
    day_after_tomorrow.setDate(15, 5, 2023);
    tomorrow.getDate();
    // print_date(); <- вызывать метод класса без вызова экземпляра нельзя, потому что он не существует

    /* day_after_tomorrow.m_day = 20;
    cout << tomorrow.m_day << endl; <- так как данные класса запривачены, использовать их нельзя */


    return 0;
}
