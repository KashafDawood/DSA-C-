#include<iostream>
using namespace std;

//class Node
class Node{

public:

    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

};

//stack class 
//it has three main methods 
//push --> to add element at the start
//pop --> to remove element 
//peek --> give the top element 

class Stack{

private: 

    Node *top;
    int Height;

public:

    //constructor
    Stack(){
        this -> top = NULL;
        this -> Height = 0;
    }

    //push method to add the element at the top of the stack
    void push(int data){
        //create a node from the node class
        Node *newNode = new Node(data);
        //check for the empty stack
        if(this -> top == NULL){
            this -> top = newNode;
            Height++;
            return;
        }
        newNode -> next = this -> top;
        this -> top = newNode;
        this -> Height++;
    }

    //pop method to remove the element from the top of the stack
    void pop(){
        //if the stack is empty
        if(top == NULL){
            cout<<"The Stack is Under-Flow or Empty"<<endl;
            return;
        }
        //point the pointer to the next element and remove the top eleemnt
        Node *remove = top;
        top = top -> next;
        free(remove);
        this -> Height--;
    }

    void peek(){
        if(top == NULL){
            return;
        }
        cout<<"The Top Item in the Stack is : "<<top -> data<<endl;
    }

    //display method
    void display(){
        //check for no node
        if(top == NULL){
            cout<<"\nStack is Under-Flow or Empty"<<endl;
            return;
        }

        //print the list
        Node *temp = top;
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
        cout<<"The Height of the Stack is : "<<Height<<endl;
    }
    

};

int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(25);
    s.display();
    s.peek();
    s.pop();
    s.display();
    s.peek();

    return 0;
}