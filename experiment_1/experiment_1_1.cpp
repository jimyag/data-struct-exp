#include <iostream>
using namespace std;
int seq_sum(int n){
    int sum = 0;
    int num = 0;
    for(int i=0;i<=n;i++){
        num = 0;
        for (int j=0;j<=i;j++){
            num+=j;
        }
        sum = sum+num;
    }
    return sum;
}

int main(){
    int maxsize = 2343;
    int n;
    cout<<"此算法是求数列1+1+2+1+2+3...+1+2+3+..+n的前n项和。"<<endl;
    cout<<"请输入你想要求的前N项和：";

    cin>>n;
    while(n<1){
        cout<<"您输入的项数不符合规范，请重新输入：";
        cin>>n;
    }
    if (n>maxsize){
        cout<<"您输入的N过大或者不符合规范，会导致溢出或运行时间过长，现已改成前"<<maxsize<<"项和"<<endl;
    }
    else maxsize =n;
    cout<<"下面将输出前"<<maxsize<<"的每一项和。"<<endl;
    for(int i=1;i<=maxsize;i++){
        cout<<"前"<<i<<"项和:";
        cout<<seq_sum(i)<<endl;
    }

    return 0;
}