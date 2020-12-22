//
// Created by jimya on 2020/11/4.
// �ݹ�ʵ��������� ֻ���޸�ͨ�ʽ���˳����������������е�ǰn���
//
#include <iostream>
using namespace  std;

//���е�ͨ�ʽan = {1,2,3,...n}
int seq_a(int n){
    return n;
}

//����ָ������
typedef int (*Fun)(int n);

//��an ��ǰn���  ֻ��Ҫ����
int seq_sum_an(Fun a,int n){
    return n==1?a(1):(seq_sum_an(a,n-1)+a(n));
    /*
    if(n==1) return a(1);
    else return sum(a,n-1)+a(n);*/
}

//��Sn = a1+a2+a3+...+an
int seq_sum_sn(int n){
    return seq_sum_an(seq_a,n);
}

//������Tn = s1+s2+...+sn;
int seq_sum_tn(int n){
    return seq_sum_an(seq_sum_sn,n);
}


int main(){
    int maxsize = 2343;
    int n = 0;

    cout<<"���㷨��������1+1+2+1+2+3...+1+2+3+..+n��ǰn��͡�"<<endl;
    cout<<"����������Ҫ���ǰN��ͣ�";
    cin>>n;

    //��׳�Լ��
    while(n<1){
        cout<<"����������������Ϲ淶�����������룺";
        cin>>n;
    }
    if (n>maxsize)
        cout<<"�������N���󣬻ᵼ�����������ʱ����������Ѹĳ�ǰ"<<maxsize<<"���"<<endl;
    else
        maxsize =n;

    cout<<"ǰ"<<maxsize<<"�����:";
    cout<<seq_sum_tn(maxsize)<<endl;
    return 0;
}
