/* This program is based on the implementation of BST(binary search tree)
using linked list as our data-structure
now, the functions that BST can be introduced with are:
1. Insert() this function let us construct the binary search tree with the fact that the left subtree
values from the node should be less and the right subtree values should be greater the node
2. lookup() this function let us return True or false if the given node exist or not.
3. remove() let us remove a node Note: we should always maintain the constraints of the BST after removal(hence
it may also required to reorder some node.)
*/

#include<iostream>
#include<stack>
using namespace std;

//node class to make nodes
class Node{

public:

    int data;
    Node *right;
    Node *left;

    //constructor
    Node(int data){
        this -> data = data;
        this -> right = NULL;
        this -> left = NULL;
    }

};

//Tree class
class BinarySearchTree{

private:

    Node *root;

public: 

    //constructor
    BinarySearchTree(){
        this -> root = NULL;
    }

    //insert method insert the node in the tree if the value is small it goes to the right side and if it small it goes to right
    void insert(int data){
        Node *newNode = new Node(data);
        Node *temp = root; //it traverse from root to downward to find where the new node is inserted

        //when the tree is empty
        if(root == NULL){
            root = newNode;
        }

        while(temp!=NULL){
            //left
            if(data < temp->data){
                if(temp->left == NULL){
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            //right
            else{
                if(temp->right == NULL){
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    void lookup(int data){
        //check for the empty tree
        if(root == NULL){
            cout<<"[WARNING] The Tree is Empty !"<<endl;
            return;
        }

        Node *temp = root;

        while(temp != NULL){
            //left
            if(data < temp->data){
                temp = temp->left;
            }
            //right
            else if(data > temp->data){
                temp = temp->right;
            }
            //when found
            else if(temp->data == data){
                cout<<"[INFO] "<<data<<" is found !"<<endl;
                return;
            }
        }
        cout<<"[INFO] "<<data<<" is not found !"<<endl;
    }

    //remove method remove the node from the tree
    void remove(int data){
        //check for the empty tree
        if(root == NULL){
            cout<<"[WARNING] The Tree is Empty !"<<endl;
            return;
        }
        
        Node *temp = root;   // pointer for traversing data if present
        Node *parent = NULL; // trailing pointer that points to the parent node(intermediate nodes)
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                parent = temp;
                temp = temp->left;
            }

            else if (data > temp->data)
            {
                parent = temp;
                temp = temp->right;
            }
            else
            {
                // looking for child nodes
                if (temp->left == NULL && temp->right == NULL)
                {
                    cout << "[INFO] We are deleting a leaf node" << endl;
                    if (parent->left == temp)
                    {
                        parent->left = NULL;
                    }
                    else
                    {
                        parent->right = NULL;
                    }
                    free(temp);
                    return;
                }
                else if (temp->left == NULL || temp->right == NULL)
                {
                    cout << "[INFO] We are deleting parent node which have one child" << endl;
                    if (temp->left != NULL&&data<root->data)
                    {
                        parent->left = temp->left;
                    }
                    else if(temp->right != NULL&&data>root->data)
                    {
                        parent->right = temp->right;
                    }
                    else if(temp->right != NULL&&data<root->data)
                    {
                    parent->left = temp->right;
                    }
                    else{
                      //checking if temp has no value in the right and data is greater than parent
                      //then the parent right value is temp's left value
                    parent->right = temp->left; 
                    }
                    free(temp);
                    return;
                }
                else
                {
                    cout << "[INFO] Deleting Node which has two children" << endl;
                    // in this case we need to find the pre-order successor.
                    Node *t = temp->right;
                    if (t->left == NULL && t->right == NULL)
                    {
                        temp->data = t->data;
                        temp->right = NULL;
                        free(t);
                        return;
                    }
                    else if (t->left == NULL && t->right != NULL)
                    {
                        temp->data = t->data;
                        temp->right = t->right;
                        free(t);
                        return;
                    }
                    while (t->left != NULL)
                    {
                        parent = t;
                        t = t->left;
                    }
                    temp->data = t->data;
                    parent->left = NULL;
                    free(t);
                    return;
                }
            }
        }
        cout << "No Nodes Found to delete" << endl;
        return;
    }

    // this display function uses in-order traversal left->root->right
    /* here we are using stack data structure for traversing */
    void display(){ 
        stack<Node *> s;
        Node *temp = root;

        while (temp != NULL || s.empty() == false)
        {

            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left; // going towards left first
            }
            temp = s.top();
            cout << temp->data << "  "; // printing the left most data.
            s.pop();

            temp = temp->right; // going towards right.
        }
    }

};

int main(){

    BinarySearchTree b;
    
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(25);
    b.insert(40); 
    b.insert(1);
    b.display();
    cout<<endl;
    b.lookup(19);
    b.remove(20);
    b.display();

    return 0;
}