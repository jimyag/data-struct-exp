//
// Created by jimya on 2020/12/16.
//

#include <iostream>
#include <fstream>
using namespace std;
int count_line(string path) {
    fstream out;
    out.open(path, ios::in);
    char buffer[256];
    int count_line_num = 0;
    while (!out.eof()) {
        out.getline(buffer, 256, '\n');
        count_line_num++;
    }
    out.close();
    return count_line_num;
}
int main(){
    cout<<count_line("../line.cpp");
    return 0;
}