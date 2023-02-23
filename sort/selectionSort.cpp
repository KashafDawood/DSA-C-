#include<iostream>
using namespace std;

//selectionsort
void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        //set the current index as minimum
        int min = i;
        int temp = arr[i];
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                //update min if current is lower that what we had previously
                min = j;
            }
        }
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(){

    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, size);
    cout<<"Sorted Array is : ";
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}