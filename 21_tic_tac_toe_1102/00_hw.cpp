#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int hw_main_files() {
    srand(time(NULL));

    ofstream file;
    file.open("../hw.txt", ios::out);
    cout << "Insert Name, Surname, Father Name, Age, City: ";
    string info;
    for (int i = 0; i < 5; i++) {
        cin >> info;
        file << info << "\n";
    }

    file.close();  // закроем файл
    ifstream read_file;
    read_file.open("../hw.txt", ios::in);
    string content;
    for (int i = 0; !read_file.eof(); i++) {
        read_file >> content;
        cout << content << endl;
    }
    read_file.close();



    return 0;
}
