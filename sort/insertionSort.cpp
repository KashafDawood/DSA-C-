#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int num = arr[i];
        int j = i - 1;

        while(j >=0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j =  j - 1;
        }

        arr[j + 1] = num;
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 22, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);

    cout<<"Sorted Array is: ";
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<"  ";
    }
}