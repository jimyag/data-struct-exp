//
// Created by jimya on 2020/12/14.
//
#include <iostream>

using namespace std;

#include <vector>

template<typename T>
void showSequence(T arr[], int low, int high) {
    cout<<"low: "<<low<<"  high: "<<high<<endl;
    for (int i = low; i <= high; i++) {
        if(i%20==0)
            cout<<endl;
        cout << arr[i] << " ";
    }
    cout << endl;
}


template<typename T>
int BinarySearch(T arr[], int n, T key) {
    int loop = 1;
    int mid;
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == arr[mid]) {
            cout << loop << " operator" << endl;
            showSequence(arr, low, high);
            cout << endl;
            ++loop;
            return mid;
        } else if (key < arr[mid]) {
            high = mid - 1;
            cout << loop << " operator" << endl;
            showSequence(arr, low, high);
            cout << endl;
            ++loop;
        } else {
            low = mid + 1;
            cout << loop << "operator" << endl;
            showSequence(arr, low, high);
            cout << endl;
            ++loop;
        }

    }
    return -1;
}


int main() {
    int arr[100];
    int len = 100;
    for (int i = 0; i < 100; i++) {
        arr[i] = i + i;
    }
    showSequence(arr, 0, len-1);
    int key = 0;
    cout<<"Please enter search number: ";
    cin>>key;
    cout<<"result :"<<endl;
    int index = BinarySearch<int>(arr, len, key);
    cout << key << " in array index : " << index << endl;
    return 0;
}
