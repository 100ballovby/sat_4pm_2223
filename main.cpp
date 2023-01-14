#include <iostream>
using namespace std;

void boo(int y) {
    /**Все аргументы по умолчанию передаются по значению.
     * При передаче аргумента по значению, он копируется в функцию. **/
    cout << "y = " << y << endl;
}

void boo_link(int &y) {
    /**В данном случае функция получает ссылку на y.
     * То есть значение аргумента не будет скопировано в функцию,
     * а функция просто обратится по ссылке и выполнит какие-то действия
     * с вашим аргументом. **/
    y += 3;
}

void boo_address(int *ptr) {
    /** Передача аргумента по адресу - это передача адреса аргумента
     * (а не исходной переменной). Посколько аргумент является адресом,
     * то параметром функции должен быть указатель. **/
    *ptr = 12;
}

int randint(int start=0, int stop=10) {  // значение параметров start и stop задаются по умолчанию
    // параметры, значения которых задается по умолчанию должны стоять последними
    return start + rand() % (stop - start) + 1;
}

void fill_array(int *array, int size, int start, int stop) {
    for (int i = 0; i < size; i++) {
        array[i] = randint(start, stop);
    }
}

void print_array(int *array, int size) {
    /**фиксированные массивы при передаче в функцию
     * распадаются на указатели, поэтому длину массива
     * передаем аргументом**/
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    int len;
    cout << "Length of array: ";
    cin >> len;
    int *arr = new int [len];  // создал динамический массив
    fill_array(arr, len, -10, 10);
    print_array(arr, len);

    cout << randint(15, 19) << endl;  // start = 15, stop = 19
    cout << randint() << endl;  // start = 0, stop = 10
    // когда у функции есть параметры по умолчанию, вы можете не передавать аргументы вообще
    return 0;
}