#include<iostream>
using namespace std;

class DynamicArray{

private:

    int *arr; //array pointer
    int capacity; //hold the actual size of array
    int totalnumber; //hold the total number of element 

public:

    //constructor
    DynamicArray(){
        arr = new int[2];
        capacity = 2;
        totalnumber = 0;
    }

    //push
    void push(int data){
        if(totalnumber == capacity){
            int *temp = new int [capacity * 2];
            for(int i = 0; i < capacity; i++){
                temp[i] = arr[i]; //copy all the array in temp
            }
            delete[] arr; //delete the allocated memory for the older array
            capacity *= 2;
            arr = temp; //pointing our array to newly allocated memory
        }
        arr[totalnumber] = data; //insert element at the end of the array
        totalnumber++;
    }

    //in this function we don't replace the orignal number
    void insert(int data, int index){
        if(index == capacity){
            push(data);
        }
        for(int i = index; i < totalnumber-1; i++){
            arr[i] = arr[i + 1];
        }
        arr[index] = data;
        totalnumber++;
    }

    //delete the last element of the array
    int pop(){
        int popELe = arr[totalnumber - 1];
        totalnumber--;
        return popELe;
    }

    //delete element at any index
    void del(int index){
        if(index > -1 && index < totalnumber){
            totalnumber--;
            for(int i = index; i < totalnumber; i++){
                arr[i] = arr[i + 1];
            }
        }
    }

    // get the data of the particular index.
    void get(int index) {
        if(index > -1 && index < capacity) {
            cout<<arr[index]<<endl;
        }
    }

    // get the size of array.
    void length(){
        cout<<"The length of array is : "<<totalnumber<<endl;
    }

    void display(){
        for(int i = 0; i < totalnumber; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

};

int main(){

    DynamicArray myArr;
    myArr.push(2);
    myArr.push(4);
    myArr.push(5);
    myArr.push(7);
    myArr.push(9);
    myArr.get(4);
    myArr.display();
    myArr.length();
    myArr.pop();
    myArr.display();
    myArr.length();
    myArr.del(1);
    myArr.display();
    myArr.length();
    myArr.insert(12, 2);
    myArr.display();
    myArr.length();

    return 0;
}