#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write_to_file(string path, int quan) {
    ofstream f;
    f.open(path, ios::out);
    int number;
    for (int i = 0; i < quan; i++) {
        cout << "number = "; cin >> number;
        f << number << "\t";
    }
    f.close();
}

void read_file(string path) {
    ifstream readfile;
    readfile.open(path, ios::in);
    string content;
    for (int i = 0; !readfile.eof(); i++) {
        readfile >> content;
        cout << content << "\n";
    }
    readfile.close();
}


int files_functions_main() {
    srand(time(NULL));

    string f_name = "../new_file.txt";
    write_to_file(f_name, 5);
    read_file(f_name);
    return 0;
}