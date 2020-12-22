//
// Created by jimya on 2020/11/4.
// 递归实现数列求和 只需修改通项公式，此程序可完成求所有数列的前n项和
//
#include <iostream>
using namespace  std;

//数列的通项公式an = {1,2,3,...n}
int seq_a(int n){
    return n;
}

//函数指针类型
typedef int (*Fun)(int n);

//求an 的前n项和  只需要传入
int seq_sum_an(Fun a,int n){
    return n==1?a(1):(seq_sum_an(a,n-1)+a(n));
    /*
    if(n==1) return a(1);
    else return sum(a,n-1)+a(n);*/
}

//求Sn = a1+a2+a3+...+an
int seq_sum_sn(int n){
    return seq_sum_an(seq_a,n);
}

//求数列Tn = s1+s2+...+sn;
int seq_sum_tn(int n){
    return seq_sum_an(seq_sum_sn,n);
}


int main(){
    int maxsize = 2343;
    int n = 0;

    cout<<"此算法是求数列1+1+2+1+2+3...+1+2+3+..+n的前n项和。"<<endl;
    cout<<"请输入你想要求的前N项和：";
    cin>>n;

    //健壮性检测
    while(n<1){
        cout<<"您输入的项数不符合规范，请重新输入：";
        cin>>n;
    }
    if (n>maxsize)
        cout<<"您输入的N过大，会导致溢出或运行时间过长，现已改成前"<<maxsize<<"项和"<<endl;
    else
        maxsize =n;

    cout<<"前"<<maxsize<<"的项和:";
    cout<<seq_sum_tn(maxsize)<<endl;
    return 0;
}
