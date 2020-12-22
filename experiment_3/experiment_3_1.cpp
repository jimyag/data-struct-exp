//
// Created by jimyag on 2020/11/13.
//
#include <iostream>
using  namespace  std;
#define MAXSIZE 20

typedef char ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;



void InitSqList(SqList &L){
    L.length = 0;
    for(int i = 0;i < MAXSIZE;i++)
        L.data[i] = 0;
    cout<<"Init successful!"<<endl;
}

void DestroySqList(SqList &L){
    L.length = 0;
    cout<<"Destroy Successful!"<<endl;

}

bool EmptySqList(SqList L){
    return L.length == 0;
}

int ListLength(SqList L){
//    cout<<"List Length!"<<endl;
    return L.length;
}

void DisplayList(SqList L){
    cout<<"Display List"<<endl;
    if(EmptySqList(L)){
        cout<<"Empty List!"<<endl;
    }
    else {
        cout<<"data : \n";
        for(int i = 0;i < ListLength(L);i++){
            cout<<"\t"<<L.data[i]<<endl;
        }
    }
}

bool GetElem(SqList L, int i, ElemType &e){
    if(i < 1 ||i > L.length){
        cout<<"GetElement Error!"<<endl;
        return false;
    }
    else {
        e = L.data[i-1];
        return true;
    }

}

int LocateElem(SqList L,ElemType x){
    int i = 0;
    while (i < L.length && L.data[i] != x){
        i++;
    }
    cout<<"Locate Element!"<<endl;
    if(i >= L.length)
        return 0;
    else
        return i+1;
}

bool InsertElem(SqList &L,int i ,ElemType e) {
    if (i - 1 > L.length || i < 1) {
        cout << "Insert Error!" << endl;
        return false;
    } else {
        int j = 0;
        for (j = L.length; j >= i; j--) {
            L.data[j] = L.data[j-1];
        }
        L.data[i-1] = e;
        ++L.length;
        cout << "Insert successful!" << endl;
        //cout << L.length << endl;
        return true;
    }
}
bool DeleteElem(SqList &L,int i,ElemType &e){
    if(i>L.length){
        cout<<"Delete Error!"<<endl;
        return false;
    }
    else {
        int j = i-1;
        e = L.data[i-1];
        while (j < L.length){
            L.data[j] = L.data[j+1];
            j++;
        }
        --L.length;
        cout<<"Delete Successful!"<<endl;
        return true;
    }
}




int main(){
    SqList L;
    InitSqList(L);

    ElemType a = 'a';
    ElemType b = 'b';
    ElemType c = 'c';
    ElemType d = 'd';
    ElemType e = 'e';

    int num = 0;
    ElemType infochar = 'a';
//    //Insert Element
//    do{
//        cout<<"please enter insert number:";
//        cin>>num;
//        cout<<"Please enter insert data:";
//        cin>>infochar;
//        while(num<0||num>L.length){
//            cout<<"Enter Error! Please insert again"<<endl;
//            cout<<"please enter insert number:";
//            cin>>num;
//            cout<<"Please enter insert data:";
//            cin>>infochar;
//        }
//        InsertElem(L,num,infochar);
//    }while(num>0&&infochar!='q');
//
//
//    do{
//        cout<<"please enter get number:";
//        cin>>num;
//    }while(num<0);
//    GetElem(L,num,infochar);
//
//
//    cout<<"please enter get data:";
//    cin>>infochar;
//    LocateElem(L,infochar);


    InsertElem(L,1,a);
    InsertElem(L,2,b);
    InsertElem(L,3,c);
    InsertElem(L,4,d);
    InsertElem(L,10,a);
    InsertElem(L,5,e);
    //display List
    DisplayList(L);
    //ListLength
    cout<<"L.length : "<<ListLength(L)<<endl;
    //isEmpty
    if(EmptySqList(L)) cout<<"\nList Empty!"<<endl;
    else cout<<"\nNOT Empty!"<<endl;
    //getElem
    ElemType x ;
    GetElem(L,3,x);
    cout<<"\n3th Element:"<<x<<endl;
    GetElem(L,11,x);
    int locateA = LocateElem(L,a);
    cout<<"\nLocate a :"<<locateA<<endl;
    ElemType f = 'f';
    InsertElem(L,4,f);
    DisplayList(L);
    DeleteElem(L,3,x);
    DisplayList(L);
    DestroySqList(L);
    return 0;
}
