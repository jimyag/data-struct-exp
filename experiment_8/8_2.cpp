//
// Created by jimya on 2020/12/14.
//
#include <iostream>
using namespace std;
#include <ctime>
using RecType = int ;


void getRandArray(RecType array[], int length) {
    int index;
    int value;
    int median;
    if (0 == length)
        return;
    srand((int) time(0));
    for (int i = 0; i < length; i++) {
        array[i] = i;
    }

    /* Arbitrarily allocate the data to be exchanged every time a card is issued */
    for (index = 0; index < length; index++) {
        value = rand() % length;
        median = array[index];
        array[index] = array[value];
        array[value] = median;
    }
}

void SelectSort(RecType R[],int n){
    int i,j,k;
    for(i = 0;i<n-1;i++){
        k = i;
        for(j = i+1;j<n;j++){
            if(R[j]<R[k])
                k=j;
        }
        if(k!=i)
            swap(R[i],R[k]);
    }
}

void display(RecType array[], int length) {
    for (int i = 1; i <= length; i++) {
        cout << array[i - 1] << " ";
        if (i % 10 == 0)
            cout << endl;
    }
}

void selectionSort(RecType array[],int length) {
    int minIndex;
    cout<<"raw array: ";
    display(array,length);
    RecType temp;
    for (int i = 0; i < length; i++) {
        minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        if(minIndex!=i)
            swap(array[i],array[minIndex]);
        cout<<i+1<<" times: ";
        display(array,length);
    }
}



int main(){
    const int len  = 10;
    RecType arr[len];
//    for(int i =1;i<len;i+=100){
//        arr = new RecType[i];
//        getRandArray(arr,i);
//        clock_t t1,t2;
//        t1= clock();
//        selectionSort(arr,i);
//        t2 = clock();
//        cout<<t2-t1<<endl;
//        delete []arr;
//    }
    getRandArray(arr,len);
    selectionSort(arr,len);



    return 0;
}
