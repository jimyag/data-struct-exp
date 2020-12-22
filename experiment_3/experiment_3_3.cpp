//
// Created by jimyag on 2020/11/13.
//
#include <iostream>

using namespace std;
typedef char ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool isFullRAM(LinkList &L) {
    if (L == NULL) {
        cout << "No Enough RAM" << endl;
        return true;
    } else return false;
}

bool InitLinkList(LinkList &L) {
    L = new LNode;
    if (isFullRAM(L)) return false;
    L->next = L;
    cout << "Init Successful!" << endl;
    return true;
}

bool LinkListEmpty(LinkList L) {
    return L == L->next;
}

bool LinkListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) {
        cout << "i Error " << endl;
        return false;
    }
    int j = 0;
    LNode *p = L;
    while (j < i - 1 && p->next != NULL) {
        p = p->next;
        ++j;
    }
    LNode *s = new LNode;
    s->data = e;
    if (L == L->next) {
        L->next = s;
        s->next = L;
        cout << "Insert Successful!" << endl;
        return true;
    }
    s->next = p->next;
    p->next = s;
    cout << "Insert Successful" << endl;
    return true;
}

bool headInsert(LinkList &L) {
    if (isFullRAM(L)) return false;
    LNode *s;
    ElemType e;
    cout << "please enter data:";
    cin >> e;
    cout << "Please enter char 'q' stop it" << endl;
    while (e != 'q') {
        s = new LNode;
        s->data = e;
        s->next = L->next;
        L->next = s;
        cout << "Please enter data:";
        cin >> e;
    }
    cout << "Head Insert Successful" << endl;
    return true;
}

bool tailInsert(LinkList &L) {
    if (isFullRAM(L)) return false;
    ElemType e;
    LNode *p = L;
    cout << "please enter data:";
    cin >> e;
    cout << "Please enter char 'q' stop it" << endl;
    while (p->next != L) {
        p = p->next;
    }
    while (e != 'q') {
        LNode *s = new LNode;
        s->data = e;
        s->next = L;
        if (L->next == L) {
            L->next = s;
        } else {
            p->next = s;
            p = s;
            cout << "Please enter data:";
            cin >> e;
        }

    }
    cout << "Tail Insert Successful" << endl;
    return true;
}

bool DisplayLinkList(LinkList L) {
    if (isFullRAM(L)) return false;
    if (L->next == L) {
        cout << "Empty LinkList" << endl;
        return false;
    }
    LNode *p = L->next;
    while (p != L) {
        cout << p->data << endl;
        p = p->next;
    }
    cout << "Display Successful" << endl;
    return true;
}

bool GetElem(LinkList L, int i, ElemType &e) {
    if (i < 1) {
        cout << "i Error " << endl;
        return false;
    }
    if (i == 1 && L != L->next) {
        e = L->next->data;
        cout << "Successful" << endl;
        return true;
    }
    int j = 0;
    LNode *p = L->next;
    while (j < i-1 && p != L) {
        p = p->next;
        ++j;
    }
    if (p == L) {
        cout << "i Error" << endl;
        return false;
    }
    e = p->data;
    cout << "Get Elem Successful" << endl;
    return true;
}

int LocateElem(LinkList L, ElemType e) {
    if (isFullRAM(L)) return false;
    int j = 0;
    LNode *p = L;
    while (p->data != e && p->next != L) {
        p = p->next;
        ++j;
    }
    if (p->data == e) {
        cout << "Locate Elem Successful" << endl;
        return j;
    } else {
        cout << "Locate Error" << endl;
        return -1;
    }
}

bool DeleteElem(LinkList &L, int i, ElemType &e) {
    if (L == NULL || L->next == L) {
        cout << "Error" << endl;
        return false;
    }
    int j = 0;
    LNode *p = L;
    while (j < i - 1 && p->next != L) {
        p = p->next;
        ++j;
    }
    if (j + 1 == i) {
        LNode *q = p->next;
        e = q->data;
        p->next = q->next;
        delete q;
        cout << "Delete Successful" << endl;
        return true;
    } else {
        cout << "Error " << endl;
        return false;
    }
}

int ListLength(LinkList L) {
    if (L == NULL) {
        cout << "L==NULL" << endl;
        return false;
    }
    int j = 0;
    LNode *p = L;
    while (p->next != L) {
        p = p->next;
        ++j;
    }
    cout << "List Length" << endl;
    return j;
}

bool freeLinkList(LinkList &L) {
    if (L == NULL) {
        cout << "L==NULL" << endl;
        return false;
    }
    LNode *p = L->next;
    LNode *pre = L;
    while (p != L) {
        delete pre;
        pre = p;
        p = pre->next;
    }
    delete pre;
    cout << "free LinkList Successful" << endl;
    return true;
}

int main() {
    LinkList L;
    InitLinkList(L);
    DisplayLinkList(L);
    tailInsert(L);
    DisplayLinkList(L);
    cout << "L_length:\n" << ListLength(L) << endl;
    ElemType e;
    GetElem(L, 3, e);
    cout << "3 element:" << e << endl;
    GetElem(L, 29, e);
    e = 'f';
    LinkListInsert(L, 4, e);
    DisplayLinkList(L);
    DeleteElem(L, 3, e);
    DeleteElem(L, 22, e);
    DisplayLinkList(L);
    freeLinkList(L);

    return 0;
}
