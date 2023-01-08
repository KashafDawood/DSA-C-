#include<iostream>
using namespace std;

//stack class
class Stack{

private:

    int *arr;//array of pointer
    int capacity, totalNumber;

public:

    //constructor
    Stack(){
        arr = new int[2];
        capacity = 2; //actual size of array
        totalNumber = 0; //total number in array
    }

    //push method to add element at the top of the stack
    void push(int data){
        // check for the full array
        if(totalNumber == capacity){
            int *temp = new int[capacity * 2];
            for(int i = 0; i < capacity; i++){
                temp[i] = arr[i]; //copy all the array 
            }
            delete[] arr; //deleting the older allocated memory
            capacity *= 2;
            arr = temp; //pointing arr to the new array
        }
        arr[totalNumber] = data;
        totalNumber++;
    }

    //pop method to remove the top item from the stack
    void pop(){
        //checking for the empty stack
        if(totalNumber == 0){
            cout<<"[Warning]Stack is Empty"<<endl;
            return;
        }
        //if the stack is not empty remove the top element
        cout<<"[INFO]Poped Element : "<<arr[totalNumber-1]<<endl;
        totalNumber--;
    }

    //display method
    void display(){
        if(totalNumber > 0){
            cout<<"The Stack elements are : ";
            for(int i = 0; i < totalNumber; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<"The Height of the Stack is : "<<totalNumber<<endl;
        }
        else{
            cout<<"[Warning]Stack is Empty"<<endl;
            return;
        }
    }

}; 

int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(9);
    s.display();
    s.pop();
    s.display();

    return 0;
}