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
                    cout << "[INFO] We are deleting '"<<data<<"' which is a leaf node" << endl;
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
                    cout << "[INFO] We are deleting '"<<data<<"' the parent node which have one child" << endl;
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
                    cout << "[INFO] Deleting '"<<data<<"' Node which has two children" << endl;
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

    //preorder root -> left -> right
    void iterativePreorder(){
        //check for empty tree
        if(root == NULL){
            cout<<"[WARNING] Tree is empty !"<<endl;
            return;
        }
        cout<<"Preorder : ";
        stack<Node *> nodeStack;
        nodeStack.push(root);
        /* Pop all items one by one. Do following for every popped item
        a) print it
        b) push its right child
        c) push its left child
        Note that right child is pushed first so that left is processed first */
        while(nodeStack.empty() == false){
            //pop root
            Node *temp = nodeStack.top();
            cout<<temp->data<<" ";
            //pop
            nodeStack.pop();
            cout<<" ";

            //push the right and the left childerns of the popped to stack
            if(temp->right){
                nodeStack.push(temp->right);
            }
            if(temp->left){
                nodeStack.push(temp->left);
            }
        }
        cout<<endl;
    }

    //postorder left -> right -> root
    void iterativePostorder(){
        //check for empty tree
        if(root == NULL){
            cout<<"[WARNING] Tree is empty !"<<endl;
            return;
        }
        cout<<"Postorder : ";
        //create two stacks
        stack<Node *> s1, s2;

        //push the root to the first stack
        s1.push(root);
        Node *temp;

        //run the loop when stack 1 is not empty
        while(!s1.empty()){
            //pop an item from s1 and push to s2
            temp = s1.top();
            s1.pop();
            s2.push(temp);

            //push the right and left childern of the removed item of s1
            if(temp->left){
                s1.push(temp->left);
            }
            if(temp->right){
                s1.push(temp->right);
            }
        }

        //print all the elementof s2
        while(!s2.empty()){
            temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }

    //inorder left -> root -> right
    void iterativeInorder(){
        //check for empty tree
        if(root == NULL){
            cout<<"[WARNING] Tree is empty !"<<endl;
            return;
        }

        cout<<"inorder : ";
        //create stack and the Node pointer
        stack <Node *> s;
        Node *temp = root;

        while(temp != NULL || s.empty() == false){
            //another loop for reach the left most node
            while(temp != NULL){
                //push temp in stack
                s.push(temp);
                temp = temp->left;
            }

            //temp must be NULL at this point
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";

            //now visited the right nodes
            temp = temp->right;
        }
    }

};

int main(){

    BinarySearchTree b;

    /*
            20
           /  \
          10  30 
          /   / \
         1   25 40 
    */
    
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(25);
    b.insert(40); 
    b.insert(1);
    b.iterativePreorder();
    b.iterativePostorder();
    b.iterativeInorder();
    cout<<endl;
    b.lookup(19);
    b.remove(20);
    b.iterativePreorder();
    b.iterativePostorder();
    b.iterativeInorder();

    return 0;
}