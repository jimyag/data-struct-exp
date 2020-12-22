//
// Created by jimya on 2020/11/4.
//

#include <iostream>
using namespace  std;
int a(int n){
    return n;
}

typedef int (*Fun)(int n);

int sum(Fun a,int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a(i);
    }
    return sum;
}
int s(int n){
    return sum(a,n);
}

int t(int n){
    return sum(s,n);
}

int main(){
    cout<<"t "<<t(5)<<endl;
    return 0;
}