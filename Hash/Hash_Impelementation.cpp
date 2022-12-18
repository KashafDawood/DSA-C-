#include<iostream>
#include <cstdlib>
#include <string>
using namespace std;
const int Array_Size = 128;

//creating the class for key value pair
class HashNode{

public:

    int key;
    int value;

    HashNode(int key, int value){
        this->key = key;
        this->value = value;
    }

};

//Hash implimentation class
class HashTable{

private:

    HashNode **arr; //array for hash node

public:

    HashTable(){
        arr = new HashNode*[Array_Size]; //creating the hash node array
        for(int i =0; i < Array_Size; i++){
            arr[i] = NULL;
        }
    }

    //creating a hash function that make a specfic value for each key
    int hashFunction(int key){
        return key % Array_Size;
    }

    //inserting the key value pair in hash table
    void insert(int key, int value){
        int h = hashFunction(key);
        while(arr[h] != NULL && arr[h]->key != key){
            h = hashFunction(h + 1);
        }
        if(arr[h] != NULL){ //if the key is already exist
            delete arr[h];
        }
        arr[h] = new HashNode(key, value);
    }

    //for getting key
    int get(int key){
        int h = hashFunction(key);
        while (arr[h] != NULL && arr[h]->key != key){
            h = hashFunction(h + 1);
        }
        if(arr[h] == NULL){//if key not found
            return -1;
        }
        return arr[h]->value; 
    }

    //for remove key value pair
    void remove(int key){
        int h = hashFunction(key);
        if(arr[h] == NULL){
            cout<<"No Element Found"<<endl;
        }
        while(arr[h] != NULL){
            if(arr[h]->key == key){
                break;
            }
            h = hashFunction(h + 1);
        }
        delete arr[h];
        cout<<"Element Deleted"<<endl;
    }

    void display(){
        for(int i = 0; i < Array_Size; i++){
            if(arr[i] != NULL && arr[i]->key != -1) {
                cout<<arr[i]->key<<"----->"<<arr[i]->value<<endl;
            }
        }
    }


};

int main(){

    HashTable h;
    h.insert(1,1);
    h.insert(2,2);
    h.insert(2,3);
    h.insert(2,8);  // note then when displayed the value of key->2 should be only 8.
    h.insert(12,21);

    h.display();

    cout<<h.get(2);

    return 0;
}