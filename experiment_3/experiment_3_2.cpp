//
// Created by jimyag on 2020/11/13.
//
#include <iostream>
using namespace std;
typedef  char ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

bool isFullRAM(LinkList &L){
    if(L==NULL) {
        cout << "No Enough RAM" << endl;
        return true;
    }
    else return false;
}

bool InitLinkList(LinkList &L){
    L = new LNode;
    if(isFullRAM(L)) return false;
    L->next = NULL;
    cout<<"Init LinkList Successful!!"<<endl;
    return true;
}

bool LinkListEmpty(LinkList L){
    return L->next==NULL;
}

bool LinkListInsert(LinkList &L,int i, ElemType e){
    if(i<1){
        cout<<"Locate Error"<<endl;
        return false;
    }
    else{
        LNode *p = L;
        LNode *s = new LNode;
        for(int j = 0;j<i-1&&p!=NULL;j++){
            p = p->next;
        }
        s->data = e;
        s->next = p->next;
        p->next = s;
        cout<<"Insert Successful!!"<<endl;
        return true;
    }
}

bool headInsert(LinkList &L){
    if(isFullRAM(L)) return false;
    LNode *s;
    ElemType x;
    cout<<"Please enter data:"<<endl;
    cin>>x;
    cout<<"Enter character string 'q' stop it"<<endl;
    while (x!='q'){
        s= new LNode;
        if(s==NULL){
            cout<<"RAM NOT Enough"<<endl;
            break;
            return false;
        }
        s->data = x;
        s->next = L->next;
        L->next= s;
        cout<<"Please enter data :";
        cin>>x;
    }
    cout<<"HeadInsert Successful"<<endl;
    return true;
}

bool tailInsert(LinkList &L){
    if(isFullRAM(L)){
        cout<<"RAM NOT"<<endl;
        return false;
    }
    LNode *s;
    ElemType x;
    cout<<"Please enter data:"<<endl;
    cin>>x;
    cout<<"Enter character string 'q' stop it"<<endl;
    LNode *p = L;
    while(p->next!=NULL){
        p=p->next;
    }
    while (x!='q'){
        s = new LNode;
        if(s==NULL){
            cout<<"RAM NOT Enough"<<endl;
            return false;
        }
        s->data = x;
        p->next =s;
        p = s;
        cout<<"Please enter data :"<<endl;
        cin>>x;
    }
    p->next =NULL;
    cout<<"Tail Insert Successful!"<<endl;
    return true;
}

bool DisplayLinkList(LinkList L){
    if(isFullRAM(L)){
        cout<<"RAM NOT"<<endl;
        return false;
    }
    LNode *p = L->next;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<"Display Successful"<<endl;
    return true;
}

bool GetElem(LinkList L,int i,ElemType &e){
    if(i<1){
        cout<<"i Error"<<endl;
        return false;
    }
    int j = 0;
    LNode *p = L;
    while (j<i&&p!=NULL){
        p=p->next;
        j++;
    }
    if(p==NULL){
        cout<<"i Error"<<endl;
        return false;
    }
    e = p->data;
    cout<<"Get Element Successful"<<endl;
    return true;
}

int LocateElem(LinkList L,ElemType e){
    if(isFullRAM(L)){
        cout<<"RAM NOT"<<endl;
        return -1;
    }
    LNode *p = L->next;
    int i = 0;
    while (p->data!=e){
        p=p->next;
        i++;

    }
    cout<<"Locate Element Successful"<<endl;
    return i+1;
}

bool DeleteElem(LinkList &L,int i,ElemType &e){
    if(i<1){
        cout<<"i Error"<<endl;
        return false;
    }
    int j = 0;
    LNode *p = L;
    while (j<i-1&&p->next!=NULL){
        p=p->next;
        ++j;
    }
    if(p->next==NULL){
        cout<<"i Error"<<endl;
        return false;
    }
    e = p->data;
    p->next = p->next->next;
    cout<<"Delete Successful"<<endl;
    return true;
}

int ListLength(LinkList L){
    if(LinkListEmpty(L)){
        cout<<"Empty"<<endl;
        return -1;
    }
    else{
        LNode *p = L;
        int j = 0;
        for(;p->next!=NULL;++j){
            p=p->next;
        }
        return j;
    }
}

bool freeLinkList(LinkList &L){
    LNode *p = L->next;
    LNode *pre = L;
    while(p!=NULL){
        delete pre;
        pre = p;
        p = pre->next;
    }
    delete pre;
    cout<<"delete LinkList Successful"<<endl;
    return true;
}
int main(){
    LinkList L;
    InitLinkList(L);
    tailInsert(L);
    DisplayLinkList(L);
    cout<<"L_length:\n"<<ListLength(L)<<endl;
    if(LinkListEmpty(L)){
        cout<<"LinkList Empty"<<endl;
    }
    else cout<<"LinkList Not Empty"<<endl;

    ElemType x;
    GetElem(L,3,x);
    cout<<"Elem third:"<<x<<endl;
    GetElem(L,89,x);
    ElemType a = 'a';
    cout<<"Elem Locate a : "<<LocateElem(L,a)<<endl;
    ElemType f = 'f';
    LinkListInsert(L,4,f);
    DisplayLinkList(L);
    DeleteElem(L,3,x);
    DeleteElem(L,99,x);
    DisplayLinkList(L);
    freeLinkList(L);
    return 0;
}
