//
// Created by jimya on 2020/11/4.
//�ݹ�ʵ��쳲���������
//

#include <iostream>
using namespace std;

//쳲��������еĵݹ��㷨 �ҵ���n��
int fib_seq_sum(int n){

    if(n==1)
        return 1;
    else if(n==2)
        return 1;
    else
        return (fib_seq_sum(n-1)+fib_seq_sum(n-2));

}


int main(){
    cout<<"�˳�������������쳲��������е�ǰn��"<<endl;
    cout<<"��������Ҫ���������47�����ڣ���";
    int seq_num = 0;
    cin>>seq_num;
    while (seq_num>47||seq_num<1){
        cout<<"���������������������47���ڵ�������";
        cin>>seq_num;
    }
    //���쳲��������е�ǰseq_num ��
    for(int i=1;i<=seq_num;i++)
        cout<<"��"<<i<<"�"<<fib_seq_sum(i)<<endl;
    
    return 0;
}