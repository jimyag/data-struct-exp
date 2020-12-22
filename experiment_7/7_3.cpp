//
// Created by jimya on 2020/12/14.
//
#include <iostream>
using namespace std;
#define NULLKEY -1
#define DELKEY -2
using KeyType = int ;
using HashTable = struct
        {
    KeyType key;
    int count;
        };
void InsertHT(HashTable ha[],int &hash_len,int hash_total, KeyType k,int p){
    int i,adr;
    adr = k%p;
    if(ha[adr].key==NULLKEY||ha[adr].key==DELKEY){
        ha[adr].key = k;
        ha[adr].count = 1;
    }
    else {
        i = 1;
        do{
            adr = (adr+1)%hash_total;
            i++;
        } while (ha[adr].key!=NULLKEY&&ha[adr].key!=DELKEY);
        ha[adr].key = k;
        ha[adr].count = i;
    }
    hash_len++;
}
void CreatHT(HashTable ha[],int &hash_len,int hash_total,KeyType keys[],int keys_len,int p){
    for(int i = 0;i<hash_total;i++){
        ha[i].key = NULLKEY;
        ha[i].count = 0;
    }
    hash_len = 0;
    for(int i = 0;i<keys_len;i++){
        InsertHT(ha,hash_len,hash_total,keys[i],p);
    }
}

void SearchHT(HashTable ha[],int hash_total,int p, KeyType k){
    int i = 1,adr;
    adr = k%p;
    while (ha[adr].key!=NULLKEY&&ha[adr].key!=k){
        i++;
        adr = (adr+1)%hash_total;
    }
    if(ha[adr].key==k)
        cout<<"Successful! key :"<<k<<" compare "<<i<< " times"<<endl;
    else
        cout<<"Fail! key :"<<k<<" compare "<<i<< " times"<<endl;
}

bool DeleteHT(HashTable ha[],int &hash_len,int hash_total,KeyType k,int p){
    int adr;
    adr = k%p;
    while (ha[adr].key!=NULLKEY&&ha[adr].key!=k){
        adr = (adr+1)%hash_total;
    }
    if(ha[adr].key==k){
        ha[adr].key = DELKEY;
        ha[adr].count = 0;
        return true;
    }
    else
        return false ;
}

void showHash(const HashTable ha[],int hash_total ){
    for(int i = 0;i<hash_total;i++){
        cout<<"key: "<<ha[i].key<<"  count: "<<ha[i].count<<endl;
    }
}

int main(){
    const int arr_len = 11;
    KeyType arr[arr_len] = {16,74,60,43,54,90,46,31,29,88,77};
    const int hash_total = 13;
    int hash_len = 0;
    HashTable ha[hash_total];
    CreatHT(ha,hash_len,hash_total,arr,arr_len,hash_total);
    showHash(ha,hash_total);

    SearchHT(ha,hash_total,hash_total,29);
    cout<<endl;
    DeleteHT(ha,hash_len,hash_total,77,hash_total);
    showHash(ha,hash_total);
    cout<<endl;
    InsertHT(ha,hash_len,hash_total,77,hash_total);
    showHash(ha,hash_total);
    return 0;
}
