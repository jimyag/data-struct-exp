//
// Created by jimya on 2020/11/18.
//
#include <iostream>
using namespace std;

#define MAXSIZE 5
typedef char ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int top;
} SqStack;

int Init = 0;
ElemType popData = 'q';

bool isEnough(SqStack *s){
    if(Init ==0) {
        cout<<"Please Init Stack"<<endl;
        return true;
    }
    if(s->top==MAXSIZE-1){
        cout<<"Enough Stack"<<endl;
        return true;
    }
    else {
        cout<<"Not Enough"<<endl;
        return false;
    }

}
bool InitStack(SqStack *&S) {
    S = new SqStack ;
    S->top = -1;
    Init = 1;
    cout<<"Init Stack Successful "<<endl;
    return true;
}
bool Destroy(SqStack *&S) {
    if(Init ==0) {
        cout<<"Please Init Stack"<<endl;
        return false;
    }
    delete S;
    Init = 0;
    cout<<"Destroy Stack Successful"<<endl;
    return true;
}
bool StackEmpty(SqStack *S) {
    if(Init ==0) {
        cout<<"Please Init Stack"<<endl;
        return true;
    }
    if(S->top==-1) {
        cout<<"Empty Stack"<<endl;
        return true;
    } else {
        cout<<"NOT Empty"<<endl;
        return false;
    }
}
bool Push(SqStack *S) {
    if(Init ==0) {
        cout<<"Please Init Stack"<<endl;
        return false;
    }
    if(S->top==MAXSIZE-1) {
        cout<<"Stack overflow"<<endl;
        return false;
    }
    ElemType e;
    cout<<"please enter char 'q' quit"<<endl;
    cout<<"please enter push_data:";
    cin>>e;
    while(!isEnough(S)&&e!='q'){
        S->top+=1;
        S->data[S->top] = e;
        cout<<"please enter push_data:";
        cin>>e;

        if(e=='q'){
            cout<<"quit Push"<<endl;
            return true;
        }
    }
    if(isEnough(S)){
        cout<<"Insert "<<e<<" Error"<<endl;
        return true;
    }
    return true;
}
bool Pop(SqStack *S) {
    if(Init ==0) {
        cout<<"Please Init Stack"<<endl;
        return false;
    }
    if(S->top==-1) {
        cout<<"Stack Empty"<<endl;
        return false;
    }
    popData = S->data[S->top];
    S->top-=1;
    cout<<"Pop Successful"<<endl;
    cout<<"Pop element:"<<popData<<endl;
    return true;
}
bool GetTop(SqStack *S) {
    if(Init ==0) {
        cout<<"Please Init Stack"<<endl;
        return false;
    }
    if(S->top==-1) {
        cout<<"Stack Empty"<<endl;
        return false;
    }
    popData = S->data[S->top];
    cout<<"Get top data successful"<<endl;
    cout<<"popData:"<<popData<<endl;
    return true;
}

bool display(SqStack *s){
    if(Init ==0) {
        cout<<"Please Init Stack"<<endl;
        return false;
    }
    if(s->top==-1) {
        cout<<"Stack Empty"<<endl;
        return false;
    }
    int a = s->top;
    int i;
    for(i = s->top;i!=-1;i--){
        cout<<s->data[i]<<" ";
    }
    s->top = a;
    cout<<"\ndisplay Successful"<<endl;
    return true;
}

void menu() {
    cout<<"This is a sequential stack test program\n "
          "please follow the instructions below"<<endl;
    cout<<"********************************************\n";
    cout<<"1.InitStack\n"
          "2.stackIsEmpty\n"
          "3.Push\n"
          "4.Pop\n"
          "5.GetTop\n"
          "6.Destroy\n"
          "7.display\n"
          "0.quit\n"
          "MAXSIZE = "<<MAXSIZE<<"\n"
          "********************************************\n";

}
SqStack *S;
void switch_menu() {
    int n = 0;
    menu();
    do {
        cout<<"please enter switch num:";

        cin>>n;
        switch (n) {
            case 0: {
                cout<<"thank you use my program"<<endl;
                cout<<endl;
                return;
            }
            case 1: {
                InitStack(S);
                cout<<endl;
                break;
            }
            case 2: {
                StackEmpty(S);
                cout<<endl;
                break;
            }
            case 3: {
                Push(S);
                cout<<endl;
                break;
            }
            case 4: {
                Pop(S);
                cout<<endl;
                break;
            }
            case 5: {
                GetTop(S);
                cout<<endl;
                break;
            }
            case 6: {
                Destroy(S);
                cout<<endl;
                break;
            }
            case 7:
                display(S);
                cout<<endl;
                break;
            default: {
                cout<<"Error! please enter again!"<<endl;
                cout<<endl;
                break;
            }
        }
    } while(n!=0);
}

int main() {
    switch_menu();
    return 0;
}
