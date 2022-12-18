#include<iostream>
using namespace std;

//Node class that create nodes
class Node{

public:

    int data;
    Node *link;

    Node(int data){
        this -> data = data;
        this -> link = NULL;
    }

};

//list class that add the node into the list
class Linklist{

private:

    Node *head;
    Node *tail;
    int totalNodes;

public:

    Linklist(){
        head = NULL;
        tail = NULL;
        totalNodes = 0;
    }

    //append method that add the node at the end of the link list
    void append(int data){
        //create node with node class
        Node *newNode = new Node(data);
        //initailze the node
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }

        //make the newNode the tail
        tail -> link = newNode;
        tail = newNode;
        totalNodes++;
    }

    //prepend method that add the node at the start of the link list
    void prepend(int data){
        //create node with node class
        Node *newNode = new Node(data);
        //initailze the node
        newNode -> link = head;
        head = newNode;
        totalNodes++;
    }

    //get the length of the link list
    void length(){
        cout<<"The length of the Link List is : "<<totalNodes<<endl;
    }

    //insert method to add the node anywhere in the link list
    void insert(int index , int data){
        //check the parameters
        if(index < 0){
            cout<<"invalid Position"<<endl;
        }
        else if(index == 0){
            //we just simply call the prepend function
            prepend(data);
        }
        else if(index >= totalNodes){
            //we just simply call the append function
            append(data);
        }
        else{
            //create node with node class
            Node *newNode = new Node(data);
            Node *prev = head;
            // we are finding the previous node w.r.t to index where we have to insert our node
            for(int i = 0; i < index - 1; i++){
                prev = prev -> link;
            }

            //assigning previos node pointer to the new node
            //newnode pointer to the next node where previos node pointing previosly
            newNode -> link = prev -> link;
            prev -> link = newNode;

            /*
            prev node                    new node                       next node
            [data,pointer to new node]-->[data, pointer to next node]-->[data, pointer to next node/null]
            */

            totalNodes++;

        }
    }

    //remove method to remove any node in link list
    void remove(int index){
        //check parameter
        if(index < 0 || index > totalNodes){
            cout<<"[WARNING] INVALID INDEX"<<endl;
        }

        //new pointer to delete node
        Node *temp = head;
        if(index == 0){
            head = head -> link;
            free(temp);
            totalNodes--;
        }
        
        //traverse the index just befor the deleting node
        for(int i = 0; temp != NULL && i < index - 1; i++){
            temp = temp -> link;
        }

        // check if the temp or pointer reference is null or not
        // if it is true it means that the node which is to be deleted is not present
        if (temp == NULL || temp->link == NULL)
        {
            return;
        }

        //creating the link b/w temp and Node after the node that is deleted
        Node *link = temp -> link -> link;

        //delete the pointer refernce 
        free(temp -> link);

        // assign the newly created link(pointer refernce) to temp -> link
        temp -> link = link;
        totalNodes--;

    }

    //get method check weather node with this index exist
    void get(int index){

        //checking parameter
        if(index < 0 || index >= this -> totalNodes){
            cout<<"[WARNING] Index is out of bounds!"<<endl;
        }

        //iterate over node until we reach the index node
        Node *current = this -> head;
        for(int i = 0; i < index; i++){
            current = current -> link;
        }

        cout<<"The node at index "<<index<<" is : "<<current -> data<<endl;

    }

    //check the node exist or not
    int find(int data){
        // Iterate through all nodes
        // In the worst case we don't find the node and reach the end of the list
        Node *curr = this->head;
        for (int i = 0; i < this->totalNodes; i++)
        {
            // Check whether we found the data, if so return the index at which it lies
            if (curr->data == data)
            {
                return i;
            } else if(curr->link == NULL)
            {
                break;
            }

            curr = curr->link;
        }
        
        // This means the loop terminated without finding the data
        cout << "Could not find the node" << endl;
        return -1;
    }

    //display method
    void display(){
        //check for no node
        if(head == NULL){
            cout<<"\nYou didn't insert any node yet\nPlease insert the Node first"<<endl;
        }

        //print the list
        Node *temp = head;
        for(int i = 0; i < totalNodes-1; i++){
            cout<<temp -> data<<" --> ";
            temp = temp -> link;
        }
        cout<<tail -> data<<endl;
    }

};

int main(){

    Linklist L;
    L.append(3);
    L.append(5);
    L.append(6);
    L.prepend(2);
    L.prepend(1);
    L.insert(0, 0);
    L.insert(10, 7);
    L.insert(4, 4);
    L.remove(0);
    L.remove(2);
    L.get(2);
    L.display();
    L.length();

    return 0;
}