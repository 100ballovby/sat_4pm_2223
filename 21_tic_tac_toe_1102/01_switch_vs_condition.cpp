#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string weekday(int day) {
    if (day == 1) {
        return "Monday";
    } else if (day == 2) {
        return "Tuesday";
    } else if (day == 3) {
        return "Wednesday";
    } else if (day == 4) {
        return "Thursday";
    } else if (day == 5) {
        return "Friday";
    } else if (day == 6) {
        return "Saturday";
    } else if (day == 7) {
        return "Sunday";
    } else {
        return "Nothing";
    }
}

string weekday_new(int day) {
    switch (day) {
        case 1: return "Monday"; // if (day == 1) ...
        case 2: return "Tuesday";  // else if (day == 2) ...
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        case 7: return "Sunday";
        default: return "Nothing"; // если нет соответствия среди переключателей
    }
}

int switch_main() {
    srand(time(NULL));
    int day = 8;
    cout << weekday(day) << endl;
    cout << weekday_new(day) << endl;

    return 0;
}