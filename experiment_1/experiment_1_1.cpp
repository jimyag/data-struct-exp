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
    cout<<"���㷨��������1+1+2+1+2+3...+1+2+3+..+n��ǰn��͡�"<<endl;
    cout<<"����������Ҫ���ǰN��ͣ�";

    cin>>n;
    while(n<1){
        cout<<"����������������Ϲ淶�����������룺";
        cin>>n;
    }
    if (n>maxsize){
        cout<<"�������N������߲����Ϲ淶���ᵼ�����������ʱ����������Ѹĳ�ǰ"<<maxsize<<"���"<<endl;
    }
    else maxsize =n;
    cout<<"���潫���ǰ"<<maxsize<<"��ÿһ��͡�"<<endl;
    for(int i=1;i<=maxsize;i++){
        cout<<"ǰ"<<i<<"���:";
        cout<<seq_sum(i)<<endl;
    }

    return 0;
}