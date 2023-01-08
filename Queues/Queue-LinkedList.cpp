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

//Queue class 
//it has three main methods 
//enqueue --> to add element at the end
//dequeue --> to remove element 
//peek --> give the last element 

class Queue{

private: 

    Node *first, *last;
    int Length;

public:

    //constructor
    Queue(){
        this -> first = NULL;
        this -> last = NULL;
        this -> Length = 0;
    }

    //enqueue method to add the element at the last of the Queue
    void enqueue(int data){
        //create a node from the node class
        Node *newNode = new Node(data);
        //check for the empty Queue
        if(this -> first == NULL){
            this -> first = newNode;
            this -> last = newNode;
            this -> Length++;
            return;
        }
        this -> last -> next = newNode;
        this -> last = newNode;
        this -> Length++;
    }

    //dequeue method to remove the element from the last of the Queue
    void dequeue(){
        //if the Queue is empty
        if(first == NULL){
            cout<<"The Queue is Under-Flow or Empty"<<endl;
            return;
        }
        //remove the last element
        Node *remove = first;
        cout<<"[INFO] Poped Item : "<<remove -> data<<endl;
        first = first -> next;
        free(remove);
        this -> Length--;
    }

    void peek(){
        //checking for the empty queue
        if(first == NULL){
            return;
        }
        cout<<"The first Item in the Queue is : "<<first -> data<<endl;
    }

    //display method
    void display(){
        //check for no node
        if(first == NULL){
            cout<<"\nQueue is Under-Flow or Empty"<<endl;
            return;
        }

        //print the list
        Node *temp = first;
        while(temp != NULL){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
        cout<<"The Length of the Queue is : "<<Length<<endl;
    }
    

};

int main(){

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(25);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    q.peek();

    return 0;
}