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

int find_max(int *array, int size) {
    int i_max = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[i_max]) {
            i_max = i;
        }
    }
    return i_max;
}

int linear_search(int *array, int size, int key) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            index = i;
            break;  // если мы нашли первое вхождение элемента, дальше не ищем
        }
    }
    return index;
}

bool is_there_even(int *array, int size, int count=0) {
    bool status = false;  // по умолчанию считаем, что в массиве нет четных чисел
    int c = 0;  // счетчик четных чисел
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {  // если в массиве встретился четный элемент
            status = true;
            c++;  // увеличиваем счетчик на 1
        }
    }
    if (count == 0) {  // если count 0 будем искать в принципе наличие четных чисел
        return status;
    } else if (count > 0 && c >= count){
        // если меня просят найти определенное количество четных чисел и значение счетчика больше/равно необходимому количеству
        return status;
    } else {  // если числа не найдены или количество чисел не совпадает с необходимым
        return false;
    }
}

int функция_main() {
    srand(time(NULL));
    int len;
    cout << "Length of array: ";
    cin >> len;
    int *arr = new int [len];  // создал динамический массив
    fill_array(arr, len, -100, 100);
    print_array(arr, len);
    int maximum = find_max(arr, len);
    cout << "Max element is: " << arr[maximum] << endl;

    cout << randint(15, 19) << endl;  // start = 15, stop = 19
    cout << randint() << endl;  // start = 0, stop = 10

    int k;
    cout << "Num: ";
    cin >> k;
    cout << linear_search(arr, len, k) << endl;
    // когда у функции есть параметры по умолчанию, вы можете не передавать аргументы вообще
    cout << "Even numbers in array: " << is_there_even(arr, len) << endl;  // есть ли в массиве в принципе четные числа?
    cout << "8 even numbers in array: " << is_there_even(arr, len, 8) << endl;  // есть ли в массиве 8 четных чисел?
    return 0;
}