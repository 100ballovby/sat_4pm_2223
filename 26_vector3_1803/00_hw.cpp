#include <iostream>
#include <vector>
using namespace std;



void hw_1803() {
    vector<string> colors { "red", "green", "blue", "yellow", "pink", "purple", "white" };
    auto start { colors.begin() };  // итератор из std:: (начало)
    auto end { colors.end() };  // итератор из std:: (конец)

    for (auto ptr{ start }; ptr != end; ptr++) {
        ptr->at(0) = toupper(ptr->at(0));
    }

    for (auto c : colors) {
        cout << c << endl;
    }
}
