// Exp12_FileIO.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "output.txt";
    ofstream ofs(filename);
    if (!ofs) { cerr << "Cannot open file to write\n"; return 1; }
    cout << "Enter a line to save: ";
    string line;
    getline(cin, line);
    ofs << line << '\n';
    ofs.close();

    ifstream ifs(filename);
    if (!ifs) { cerr << "Cannot open file to read\n"; return 1; }
    cout << "Content from file:\n";
    while (getline(ifs, line)) cout << line << '\n';
    ifs.close();
    return 0;
}
