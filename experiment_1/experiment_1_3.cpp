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
    cout<<"����һ����֤�ǹŲ���ĳ���\n"<<endl;
    cout<<"�ǹȲ��룺����һ����Ȼ������Ϊż�������2��\n"
          "��Ϊ�������3��1���õ�һ���µ���Ȼ����\n"
          "Ȼ��������ķ���������㣬\n"
          "���ɴκ�õ��Ľ����Ȼ��1��\n"
          <<endl;
    cout<<"������������֤������:";
    int guess_num = 0;
    cin>>guess_num;
    while (guess_num<0||guess_num>INT_MAX){
        cout<<"���������������������������Ч�����֣�";
        cin>>guess_num;
    }
    jg_con(guess_num);
    return 0;
}