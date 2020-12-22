#include "File.hpp"
#include <iostream>

int getLnCount(string content){
    int count = 0;
    for(auto &i:content){
        count += (i=='\n')?1:0;
    }
    return count;
}

int main(){
    Path p(string(".."));
    FileTraverser ft(p);
    ft.addFilter([](Path p){
        bool b1 = p.getExtension()==".cpp";
        bool b2 = p.getExtension()==".h";
        bool b3 = p.getExtension()==".hpp";
        return b1||b2||b3;
    });
    ft.addFilter([](Path p){
        return p.getFileName()!="CMakeCXXCompilerId.cpp";
    });
    ft.start();
    for(auto &i:ft.getResult()){

        string content = i.readAsText();
        cout<<getLnCount(i.readAsText())<<"  "<<i<<endl;
    }
    return 0;
}