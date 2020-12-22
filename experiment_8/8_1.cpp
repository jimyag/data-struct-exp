//
// Created by jimya on 2020/12/14.
//
#include <iostream>

using namespace std;

#include <ctime>

using RecType = int;

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

void display(RecType array[], int length) {
    for (int i = 1; i <= length; i++) {
        cout << array[i - 1] << " ";
        if (i % 10 == 0)
            cout << endl;
    }
}

void InsertSort(RecType R[], int n) {
    cout<<"raw array: ";
    display(R,n);
    for (int i = 1; i < n; i++) {
        int temp = R[i];
        int j;
        for (j = i - 1; j >= 0 && temp < R[j]; j--) {
            R[j + 1] = R[j];    //将较大元素后移
        }
        R[j + 1] = temp;        //temp插入正确的位置
        cout<<i<<" times : ";
        display(R,n);
    }
}


int main() {
    const int len = 10;
    RecType arr[len];
    getRandArray(arr, len);
    InsertSort(arr, len);
    //    RecType *arr;
//    for(int i =1;i<len;i+=100){
//        arr = new RecType[i];
//        getRandArray(arr,i);
//        clock_t t1,t2;
//        t1= clock();
//        InsertSort(arr,i);
//        t2 = clock();
//        cout<<t2-t1<<endl;
//        delete []arr;
//    }
    return 0;
}
