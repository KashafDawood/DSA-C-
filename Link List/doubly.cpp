#include<iostream>
using namespace std;

//node class 
class Node{

public:

    //as this is the doubly link list it has 
    //one previous pointer 
    //one next pointer 
    //and data
    Node *next, *pre;
    int data;

    //constructor
    Node(int data){
        next = NULL;
        this -> data = data;
        pre = NULL;
    }

};

//doubly link list class that add the nodes 
class DoublyLinkList{

private: 

    Node *head, *tail;
    int totalNodes;

public:

    //constructor
    DoublyLinkList(){
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    //append method to add the node at the end of DLL
    void append(int data){
        //create a new node with node class
        Node *newNode = new Node(data);

        //check for the empty DLL
        if(totalNodes == 0){
            head = newNode;
            tail = newNode;
        }

        //link the pre pointer of the newnode to previous node and make the newnode a tail
        newNode -> pre = tail;
        tail -> next = newNode;
        tail = newNode;
        totalNodes++;
    }

    //prepend Method that add the node that the end of the DLL
    void prepend(int data){
        //creatng new node with node class
        Node *newNode = new Node(data);

        //next pointer of new node points to previouly head node and pre pointer of the prevoiuly head node points to new node and make the new node a head node
        head -> pre = newNode;
        newNode -> next = head;
        head = newNode;
        totalNodes++;
    }

    //insert method can add the node anywhere in the DLL
    void insert(int index , int data){
        //checking parameter
        if(index < 0){
            cout<<"[WARNING] Wrong position\nPlease input index 0 or grater than 0"<<endl;
            return;
        }
        else if(index == 0){
            //its mean he want to add the node at the start
            //then simply call the prepend function
            prepend(data);
        }
        else if(index >= totalNodes){
            //it mean he want to add at the end 
            //then simply call the append method
            append(data);
        }
        else{
            Node *newNode = new Node(data);
            //call the traverse method and save the result in curr
            Node *curr = traverse(index - 1);
            //make the curr next pointer points to new node the node points to next node
            newNode -> next = curr -> next;
            newNode -> pre = curr;
            curr -> next = newNode;
            totalNodes++;
        }
    }

    // remove mthod remove the node from DLL
    void remove(int index){
        //checking parameter
        if(index < 0 || index > totalNodes){
            cout<<"[Warning] INVALID index"<<endl;
            return;
        }
        else{
            //traverse to the node before the removing node
            Node *curr = traverse(index - 1);
            //for removing the node the next of curr points to node next to removing node and that node points to curr and then free the removing node            
            //creating the new nodes with the addresses store in the pointers of removing node and next node of the removing node
            Node *removingNode = curr -> next;
            Node *nextNode = removingNode -> next;
            curr -> next = nextNode;
            nextNode -> pre = curr;
            free(removingNode);
            totalNodes--;
        }
    }

    //reverselist method reverse the DLL
    void reverse(){
        Node *temp = NULL;
        Node *current = head;

        //swaping all the next and pre pointers of the nodes
        while(current != NULL){
            temp = current -> pre;
            current -> pre = current -> next;
            current -> next = temp;
            current = current -> pre;
        }

        // checking the edge case
        if(temp != NULL){
            head = temp -> pre;
        }
    }

    //traverse method can traverse in a DLL
    Node *traverse(int index){
        Node *current = head;
        for(int i = 0; i < index; i++){
            current = current -> next;
        }
        return current;
    }

    //length method give the length of DLL
    void length(){
        cout<<"The length of the Doubly link list is : "<<totalNodes<<endl;
    }

    //display method
    void display(){
        //checking parameters
        if(head == NULL){
            cout<<"\n[WARNING] Your list is Empty\n"<<endl;
            return;
        }

        Node *current = head;
        for(int i = 0; i < totalNodes - 1; i++){
            cout<<current -> data<<" --> ";
            current = current -> next;
        }
        cout<<tail -> data<<endl;
        //call the length method
        length();
    }

};

int main(){

    DoublyLinkList l;

    l.append(2);
    l.append(1);
    l.append(3);
    l.append(5);
    l.prepend(9);
    l.prepend(12);
    l.prepend(45);
    l.insert(0, 55);
    l.insert(20, 99);
    l.insert(3, 11);
    l.insert(4, 10);
    l.remove(1);
    l.remove(5);
    l.remove(7);

    l.display();

    return 0;
}