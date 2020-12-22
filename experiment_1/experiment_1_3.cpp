//
// Created by jimya on 2020/11/4.
//
#include <climits>
#include <iostream>
using namespace std;
void jg_con(int n){
    if(n==1) {
        cout<<1<<endl;
        return ;
    }
    if(n%2==0) {
        cout<<n<<"/2 = "<<n/2<<endl;
        jg_con(n/2);
    }
    else {
        cout<<"3*"<<n<<"+1 = "<<3*n+1<<endl;
        jg_con(3*n+1);
    }
}



int main(){
    cout<<"这是一个验证角古猜想的程序。\n"<<endl;
    cout<<"角谷猜想：任意一个自然数，若为偶数则除以2，\n"
          "若为奇数则乘3加1，得到一个新的自然数，\n"
          "然后按照上面的法则继续演算，\n"
          "若干次后得到的结果必然是1。\n"
          <<endl;
    cout<<"请输入您想验证的数字:";
    int guess_num = 0;
    cin>>guess_num;
    while (guess_num<0||guess_num>INT_MAX){
        cout<<"您输入的数字有误，请重新输入有效的数字：";
        cin>>guess_num;
    }
    jg_con(guess_num);
    return 0;
}