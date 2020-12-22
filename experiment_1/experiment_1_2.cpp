//
// Created by jimya on 2020/11/4.
//递归实现斐波那契数列
//

#include <iostream>
using namespace std;

//斐波那契数列的递归算法 找到第n项
int fib_seq_sum(int n){

    if(n==1)
        return 1;
    else if(n==2)
        return 1;
    else
        return (fib_seq_sum(n-1)+fib_seq_sum(n-2));

}


int main(){
    cout<<"此程序是来完成输出斐波那契数列的前n项"<<endl;
    cout<<"请输入您要求的项数（47项以内）：";
    int seq_num = 0;
    cin>>seq_num;
    while (seq_num>47||seq_num<1){
        cout<<"您输入的项数有误，请输入47以内的项数：";
        cin>>seq_num;
    }
    //输出斐波那契数列的前seq_num 项
    for(int i=1;i<=seq_num;i++)
        cout<<"第"<<i<<"项："<<fib_seq_sum(i)<<endl;
    
    return 0;
}