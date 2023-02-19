#include<iostream>
using namespace std;

//structure to store Adjacency list nodes
struct Node{
    int value;
    Node * next;
};

//structure to store graph edges
struct Edge{
    //source and deatination
    int src, dest;
};

//graph class
class Graph{

private:

    int N; //number of nodes in the graph

    //function to allocate a new node of adjacency list
    Node *getAdjListNode(int dest, Node* head){
        Node *newNode = new Node;
        newNode->value = dest;
        newNode->next = head;

        return newNode;
    }

public:

    //an array of pointers to node to represent adjacency list
    Node **head;
    Graph(Edge edges[], int n, int N){
        head = new Node*[N]();
        this->N = N;

        //initiate head pointer for all vertices
        for(int i = 0; i < n; i++){
            int src = edges[i].src;
            int dest = edges[i].dest;
            Node *newNode = getAdjListNode(dest, head[src]); //inserting at the beginning
            head[src] = newNode;
        }
    }

};

void printList(Node *ptr){
    while(ptr != nullptr){
        cout<<" -> "<<ptr->value<<" ";
        ptr = ptr -> next; 
    }
    cout<<endl;
}

int main(){

    // array of graph edges as per above diagram.
	Edge edges[] = {
		// pair (src, dest) represents edge from src to dest
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};

	int N = 6;
	int n = sizeof(edges)/sizeof(edges[0]);

	Graph graph(edges, n, N);
	for (int i = 0; i < N; i++) {
		cout << i << " --";
		printList(graph.head[i]);
	}

    return 0;
}