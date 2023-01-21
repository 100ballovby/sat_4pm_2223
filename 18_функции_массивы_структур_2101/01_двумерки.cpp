#include <iostream>
using namespace std;

int randint(int start, int end) {
    // функция получает промежуток чисел и в рамках него генерирует случайные
    int num = start + rand() % (end - start + 1); // если не будет +1, то конец промежутка не будет включен
    return num;
}


void fill_matrix(int **array, int lines, int cols) {
    for (int i = 0; i < lines; i++) {
        array[i] = new int [cols];  // создаем вложенный массив на определенное количество элементов
        for (int j = 0; j < cols; j++) {
            array[i][j] = randint(-100, 100);  // заполняем элементы матрицы
        }
    }
}

void print_matrix(int **array, int lines, int cols) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_magic_square(int **array, int lines) {
    bool magic_square = true;
    int main_sum = 0, sum;

    // напишем цикл, который будет считать сумму в первой строке матрицы
    for (int i = 0; i < lines; i++) {
        main_sum += array[0][i];  // беру каждое число из первой строки матрицы
    }

    // сначала определим, равны ли суммы чисел строк матрицы главной сумме
    for (int i = 1; i < lines; i++) {
        sum = 0;
        for (int j = 0; j < lines; j++) {
            sum += array[i][j];
        }
        // если посчитанная сумма не равна главной сумме - выходим из функции и возвращаем false
        if (sum != main_sum) return false;
    }

    // определим, равны ли суммы чисел СТОЛБЦОВ матрицы главной сумме
    // чтобы пройтись по столбцам матрицы, поменяйте обращение к элементу на [j][i]
    for (int i = 0; i < lines; i++) {
        sum = 0;
        for (int j = 0; j < lines; j++) {
            sum += array[j][i];  // элемент из каждого столбца добавляю к сумме
        }
        // если посчитанная сумма не равна главной сумме - выходим из функции и возвращаем false
        if (sum != main_sum) return false;
    }

    // определим, равна ли сумма чисел ГЛАВНОЙ диагонали матрицы главной сумме
    // помните, что индексы строки и столбца на главной диагонали совпадают
    sum = 0;
    for (int i = 0; i < lines; i++) {
        sum += array[i][i];
    } if (sum != main_sum) return false;

    // определим, равна ли сумма чисел ПОБОЧНОЙ диагонали матрицы главной сумме
    sum = 0;
    for (int i = 0; i < lines; i++) {
        sum += array[i][lines - 1 - i];
    } if (sum != main_sum) return false;


    return magic_square;
}

int это_main_функция() {
    srand(time(NULL));
    int n, m;
    cout << "Insert dimension (n m): ";
    cin >> n >> m;  // если записать числа через пробел, то первое уйдет в n, второе m

    int **mtrx = new int *[n];
    fill_matrix(mtrx, n, m);
    print_matrix(mtrx, n, m);

    cout << "Is matrix mtrx magic square? " << is_magic_square(mtrx, n) << endl;
    return 0;
}