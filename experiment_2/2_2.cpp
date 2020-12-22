//
// Created by jimyag on 2020/11/8.
//

#include<iostream>
#include <iomanip>
using namespace std;

void display_tips();

void ballSolution(int red,int white,int black,int num);
int main(){
    display_tips();
    ballSolution(3,3,6,8);
    ballSolution(4,5,6,11);
    return 0;
}

void display_tips(){
    cout<<"****************************************************************\n"
          "*    This program is to solve Problem of Three Color Ball.     *\n"
          "* The Problem is as follows: There are 12 balls in the pocket. *\n"
          "* Among them, 3 balls are red,3 balls are white and 6 balls    *\n"
          "* are black. Now take out any 8 balls from the pocket,how many *\n"
          "* color combinations are there?                                *\n";
    cout<<"****************************************************************\n"
          ">> The solutions are : \n";
    cout<<setw(5)<<"No."<<setw(14)<<"RED BALL"
        <<setw(11)<<"WHITE BALL"<<setw(11)<<"BLACK BALL"<<endl;

}

void ballSolution(int red,int white,int black,int num){
    cout<<"----------------------------------------------------------------\n";
    int k = 1;
    for(int i = 0;i <= red;i++){
        for(int j = 0;j <= white;j++){
            for(int m = 0;m <= black;m++){
                if((i+j+m)==num){
                    cout<<setw(5)<<k
                        <<setw(5)<<"|"
                        <<setw(5)<<i
                        <<setw(5)<<"|"
                        <<setw(5)<<j
                        <<setw(5)<<"|"
                        <<setw(5)<<m
                        <<endl;
                    k++;
                }
            }
        }
    }
    cout<<"----------------------------------------------------------------\n"<<endl;
}