#include <iostream>
#include <vector>
using namespace std;


void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {  // явный индекс
        cout << v[i] << ' ';
    }
    cout << endl;
}

vector<int> test(vector<int> &nums) {
    vector<int> tbd;  // временная хранилка
    for (auto i = 0; i < nums.size(); i++) {
        if ((nums[i] < nums[i - 1]) && (nums[i] < nums[i + 1])) {
            tbd.push_back(nums[i]);
        }
    }
    return tbd;
}

int task_vector_neighbors() {
    /* Напишите функцию, которая возвращает элементы вектора, строго меньшие, чем их соседи слева и справа. */
    vector<int> data{ 7, 2, 5, 3, 1, 5, 6, 0, 8 };
    auto start { data.begin() };  // итератор из std:: (начало)
    auto end { data.end() };  // итератор из std:: (конец)
    cout << "Original vector: ";
    print_vector(data);
    vector<int> res = test(data);
    cout << "Elements smaller than its neighbors: ";
    print_vector(res);
    return 0;
}