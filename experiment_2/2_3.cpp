//
// Created by jimyag on 2020/11/8.
//
#include<iostream>
#include <iomanip>
using namespace std;

int classMember();

void inputsScores(int n,float *scoreArr);

void calAvSc(int n,float *scoreArr,float *aver);

void display(int n,float *scoreArr,float *av);

int main() {
    int n = classMember();

    float scoreArr[n * 3];
    float av[n];

    inputsScores(n,scoreArr);

    calAvSc(n,scoreArr,av);

    display(n,scoreArr,av);

    return 0;
}
int classMember(){
    cout<<"****************************************************************\n"
          "* This program displays class grades and their average scores, *\n"
          "* you only need to follow the prompts to enter the data.       *\n"
          "****************************************************************\n";
    int n = 0;
    cout<<">> how many students are in your class ? ";
    cin>>n;
    while(n<1){
        cout<<"Error member !\n"
              "Please enter data again .";
        cin>>n;
    }
    return n;
}

void inputsScores(int n,float *scoreArr){
    cout<<"Please follow the example below to enter a student’s three lessons：\n"
          "the no.1 : 77,84,90\n"
          "Please start typing as prompted ！\n";

    int j = 0;
    for (int i = 0; i < n * 3 - 2; i = i + n) {
        cout <<"the no." << j + 1 << " : ";
        char ch = 'q';
        float a = 0.0;
        float b = 0.0;
        float c = 0.0;
        cin >> a >> ch
            >> b >> ch
            >> c;
        while (a < 0.0 | b < 0.0 | c < 0.0) {
            cout << "Please enter valuable scores!\n";
            cout << "the no." << j + 1 << " : ";
            cin >> a >> ch
                >> b >> ch
                >> c;
        }
        scoreArr[i] = a;
        scoreArr[i + 1] = b;
        scoreArr[i + 2] = c;
        j++;
    }
    cout<<"----------------------------------------------"<<endl;
}

void calAvSc(int n,float *scoreArr,float *av){
    int j = 0;
    for(int i = 0;i < n*3 - 2;i = n + i){
        av[j] = (scoreArr[i]+scoreArr[i+1]+scoreArr[i+2])/3;
        j++;
    }
}

void display(int n,float *scoreArr,float *av){
    cout<<setw(7)<<"num"
        <<setw(7)<<"a"
        <<setw(7)<<"b"
        <<setw(7)<<"c"
        <<setw(7)<<"av"
        <<endl;
    int j = 0;
    float  cla_av = 0.0;
    for(int i = 0;i < n*3-2;i = n + i){
        cout<<setw(7)<<setiosflags(ios::fixed)<<setprecision(2) <<j+1
            <<setw(7)<<setiosflags(ios::fixed)<<setprecision(2) <<scoreArr[i]
            <<setw(7)<<setiosflags(ios::fixed)<<setprecision(2) <<scoreArr[i+1]
            <<setw(7)<<setiosflags(ios::fixed)<<setprecision(2) <<scoreArr[i+2]
            <<setw(7)<<setiosflags(ios::fixed)<<setprecision(2) <<av[j]
            <<endl;
        cla_av = cla_av + av[j];
        j++;
    }
    cla_av /=n;
    cout<<"----------------------------------------------"<<endl;
    cout<<"average of the class = "<<cla_av<<endl;
}
