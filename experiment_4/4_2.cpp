//
// Created by jimya on 2020/11/18.
//
#include<iostream>
using namespace std;

#define MAXSIZE 5
typedef char ElemType;
ElemType x = 'q';
int Init = 0;

typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;

bool isNULL(){
    if(Init ==0){
        cout<<"please Init Queue "<<endl;
        return true;
    }
    return false;
}
bool InitQueue(SqQueue *&s){
    s = new SqQueue ;
    s->front = s->rear = 0;
    Init = 1;
    cout<<"InitQueue Successful\n"<<endl;
    return true;
}
bool DestroyQueue(SqQueue *&s){
    if(isNULL()) {
        return false;
    }

    delete s;
    s=NULL;
    cout<<"Destroy Queue Successful\n"<<endl;
    Init =0;
    return true;
}
bool isEmpty(SqQueue *s){
    if(isNULL()) return false;
    if(s->rear==s->front){
        cout<<"Empty Queue"<<endl;
        return true;
    }
    else{
        cout<<"Not Empty"<<endl;
        return false;
    }
}

bool isEnough(SqQueue *s){
    if(isNULL()) return false;
    if((s->rear+1)%MAXSIZE==s->front){
        cout<<"Queue Enough"<<endl;
        return true;
    }
    cout<<"Queue not Enough"<<endl;
    return false;
}
bool enQueue(SqQueue *&s){
    if(isNULL()) return false;
    if(isEnough(s)) return false;
    ElemType x = 'q';
    cout<<"enter char 'q' quit it!\n";
    cout<<"Please enter  element:";
    cin>>x;
    if(x=='q') return true;
    while (!isEnough(s)&&x!='q'){
        s->data[s->rear] = x;
        s->rear = (s->rear+1)%MAXSIZE;
        cout<<"Please enter Insert element:";
        cin>>x;
        if(x=='q'){
            cout<<"quit successful!\n"<<endl;
            return true;
        }
    }
    if(isEnough(s)){
        cout<<"Insert "<<x<<" Error\n"<<endl;
        return true;
    }
    cout<<"enQueue Successful\n"<<endl;
    return true;
}
bool deQueue(SqQueue *&s){
    if(isNULL()) return false;
    if(isEmpty(s)) return false;
    x = s->data[s->front];
    s->front = (s->front+1)%MAXSIZE;
    cout<<"deQueue Successful"<<endl;
    cout<<"De Element :"<<x<<"\n"<<endl;
    return true;
}

int SqQueue_length(SqQueue *s){
    return (s->rear+MAXSIZE-s->front)%MAXSIZE;
}
bool display(SqQueue *s){
    int i ;
    if(isNULL()) return false;
    if(!isEmpty(s)) {
        int a = s->front;
        for (i = 0; s->rear != s->front; ++i) {
            cout << s->data[s->front] << " ";
            s->front = (s->front + 1) % MAXSIZE;
        }
        s->front = a;
        cout << "length:" <<SqQueue_length(s)<< endl;
        cout << "display Successful" << endl;
    }
    return true;
}

void menu() {
    cout<<"This is a sequential Queue test program\n "
          "please follow the instructions below"<<endl;
    cout<<"********************************************\n";
    cout<<"1.InitQueue\n"
          "2IsEmpty\n"
          "3.enQueue\n"
          "4.deQueue\n"
          "5.isEnough\n"
          "6.DestroyQueue\n"
          "7.display\n"
          "0.quit\n"
          "MAXSIZE = "<<MAXSIZE<<"\n"
          "********************************************\n";
}

void switch_menu() {
    SqQueue *S;
    int n = 0;
    menu();
    do {
        cout<<"please enter switch num:";
        cin>>n;
        switch (n) {
            case 0: {
                cout<<"thank you use my program"<<endl;
                return;

            }
            case 1: {
                InitQueue(S);
                break;
            }
            case 2: {
                isEmpty(S);
                cout<<endl;
                break;
            }
            case 3: {
                enQueue(S);
                display(S);
                cout<<endl;
                break;
            }
            case 4: {
                deQueue(S);
                display(S);
                cout<<endl;
                break;
            }
            case 5: {
                isEnough(S);
                cout<<endl;
                break;
            }
            case 6:
                DestroyQueue(S);
            case 7:
                display(S);
                cout<<endl;
                break;
            default: {
                cout<<"Error! please enter again!"<<endl;
                break;
            }
        }
    } while(n!=0);
}
int main(){
    switch_menu();
    return 0;
}
