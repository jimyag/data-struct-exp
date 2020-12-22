//
// Created by jimyag on 2020/11/8.
//
//
#include <iostream>
#include <math.h>
using namespace std;

bool primeNumber(int x);

void num(int m,int k ,int kk[]);

void display(int m,int k, int kk[]);

void inputMK(int mk[]);

int * inputsMK(){
    int * a = new int[2];
    cout<<">> Please input two integers to m and k : ";
    int m ;
    int k;
    cin>>m>>k;

    while(m < 1 || k < 1){
        cout<<"please input valuable m and k :";
        cin>>m>>k;
    }
    a[0] = m;
    a[1] = k;
    return  a;
}

int main(){
    cout<<"************************************************************"<<endl;
    cout<<"T program is to get k prime numbers which are larger than m."<<endl;
    cout<<"************************************************************"<<endl;
    int mk[2];
    inputMK(mk);
    int *kk = new int[mk[1]];
    num(mk[0],mk[1],kk);
    display(mk[0],mk[1],kk);
    delete []kk;
/*
 //new arr
    int * a = inputsMK();
    cout<<a[1]<<endl;
    delete []a;
    return 0;
*/
}

bool primeNumber(int x){
    bool  is = true;

    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0) {
            is = false;
            break;
        }
    }
    return is;
}

void num(int m,int k ,int kk[]){
    int i = m+1;int j = 0;

    for(;j < k;){
        if(primeNumber(i)){
            kk[j] = i;
            j++;
            i++;
        }
        else i++;
    }
}

void display(int m,int k,int kk[]){
    cout<<">> The "<<k<< " prime numbers which are larger than "<<m<<" are :"<<endl<<"\t";
    for(int i = 0;i < k;i++){
        cout<<kk[i]<<" ";
    }
}

void  inputMK(int mk[]){
    cout<<">> Please input two integers to m and k : ";
    int m ;
    int k;
    cin>>m>>k;

    while(m < 2 || k < 1){
        cout<<"please input valuable m and k :";
        cin>>m>>k;
    }
    mk[0] = m;
    mk[1] = k;
}