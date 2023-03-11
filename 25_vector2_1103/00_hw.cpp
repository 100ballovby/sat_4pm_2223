#include <iostream>
#include <vector>
using namespace std;


void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void hw_vec_task1() {
    vector<int> vec;
    int n, k;
    cout << "Vector length: "; cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "k = "; cin >> k;
        vec.push_back(k);
    }
    print_vector(vec);
}

void hw_vec_task2() {
    vector<int> vec {1, 3, 5, 7, 9};
    int index;
    cout << "place: "; cin >> index;
    auto start = vec.begin();  // 0 (первый элемент)

    vec.insert(start + index, 5, 15);
    print_vector(vec);
}