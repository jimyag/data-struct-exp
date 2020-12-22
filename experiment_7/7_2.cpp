//
// Created by jimya on 2020/12/14.
//
#include<iostream>

using namespace std;

template<typename t>
struct BSTNode {
    t key;
    struct BSTNode *lChild, *rChild;
};

template<typename T>
bool InsertBST(BSTNode<T> *&bt, T key) {
    if (bt == nullptr) {
        bt = new BSTNode<T>;
        bt->key = key;
        bt->lChild = bt->rChild = nullptr;
        return true;
    } else if (key == bt->key) {
        return false;
    } else if (key < bt->key) {
        return InsertBST(bt->lChild, key);
    } else {
        return InsertBST(bt->rChild, key);
    }
}

template<typename t>
BSTNode<t> *CreatBST(t arr[], int len) {
    BSTNode<t> *bt = nullptr;
    int i = 0;
    while (i < len) {
        InsertBST(bt, arr[i]);
        i++;
    }
    return bt;
}

template<typename t>
void PreOrder(const BSTNode<t> *bt) {
    if (bt != nullptr) {
        cout << bt->key;
        if (bt->lChild == nullptr && bt->rChild == nullptr)
            return;
        cout << "(";
        PreOrder(bt->lChild);
        cout << ",";
        PreOrder(bt->rChild);
        cout << ")";
    }
}

template<typename t>
BSTNode<t> *findNode(BSTNode<t> *bt, t key) {
    if (bt->key == key) {
        cout << " -> " << bt->key << endl;
        return bt;
    } else if (key > bt->key) {
        cout << " -> " << bt->key;
        findNode(bt->rChild, key);
    } else {
        cout << " -> " << bt->key;
        findNode(bt->lChild, key);
    }
}
template<typename t>
void display(t arr[],int len){
    for(int i = 0;i<len;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    using type = int;
    const int len = 10;
    type arr[len] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7};
    cout<<"array: ";
    display(arr,len);
    BSTNode<type> *BT = CreatBST(arr, len);
    cout<<"PreOrder : ";
    PreOrder<type>(BT);
    cout << endl;
    type key = 0;
    cout<<"please enter search key:";
    cin>>key;
    BSTNode<type> *bt = findNode(BT, key);
    cout << bt->key << endl;
    return 0;
}
