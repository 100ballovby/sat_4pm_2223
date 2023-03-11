#include <iostream>
#include <vector>
#include <string>
using namespace std;


void print_vector(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {  // явный индекс
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {
    vector<string> colors { "red", "green", "blue", "yellow", "pink", "purple", "white" };
    auto start { colors.begin() };  // итератор из std:: (начало)
    auto end { colors.end() };  // итератор из std:: (конец)

    return 0;
}