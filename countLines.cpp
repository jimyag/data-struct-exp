//
// Created by zhiqingzs and jimyag on 2020/12/14.
//
#include<iostream>
#include <filesystem>
#include <fstream>

using namespace std::filesystem;
using namespace std;

static int count_file = 0, count_dir = 0;
static int count_cpp = 0;
static int count_line_sum = 0;

bool isCppFile(string file_name) {
    string sub = file_name.substr(file_name.size() - 4, 4);
    return sub == string(".cpp");
}

//Count the number of file lines
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

void visitCallback(path pa, int deep) {
    directory_entry entry(pa);
    file_type t = entry.status().type();
    bool isFile = t != file_type::directory;
    if (isFile) {
        count_file++;
        string file_name = pa.filename().string();
        if (isCppFile(file_name)) {
            count_cpp++;
            int line_sum = count_line(pa.string());
            count_line_sum += line_sum;
            cout << file_name << " : " << line_sum << endl;
        }
    } else {
        count_dir++;
    }
}

void it(path pa) {
    static int deep = 0;
    directory_entry entry(pa);
    file_type t = entry.status().type();
    bool isFile = t != file_type::directory;
    visitCallback(pa, deep);
    if (!isFile) {
        directory_iterator list(pa);
        deep++;
        for (auto &iter:list) {
            it(iter);
        }
        deep--;
    }
}

int main() {
    path pa("..");
    cout << absolute(pa).string() << endl;
    it(pa);
    cout << "count_file:" << count_file << endl;
    cout << "count_dir:" << count_dir << endl;
    cout << "count_cpp:" << count_cpp << endl;
    cout << "sun_lines : " << count_line_sum << endl;
    return 0;
}
