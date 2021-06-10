
#include <iostream>

using namespace std;

//used this to understand arrays with pointers more
//https://stackoverflow.com/questions/21420772/array-of-linked-lists-c

//string array representing the hash table
string hash_array[10]={};

struct node{
    string data;
    node *next_node;
};

//creates key for input takes ascii value of each key letter then divide by table length and uses remainder for the key
int make_hash(string key){
    int hash_number=0;
    int array_length=10;
    for (int i=0; i<key.length();i++){
        hash_number=hash_number+ int(key[i]);
    }    
    int hash_key= hash_number%array_length;
    return hash_key;
}
//adds input to array position of it's key
void hash_add(string key){
    int hash_key=make_hash(key);
    hash_array[hash_key]=key;
}
//checks if input is in hash table
void contains(string key){
    int hash_key=make_hash(key);
    if (hash_array[hash_key]==key){
        cout<<"Value is in hashtable"<<"\n";
    }
    else{
        cout<<"Value not found"<<"\n";
    }
}
//creates an array of node pointers to be used for linked list
node** create_linked_array(){
    node** array_pointers = new node*[10];
    for(int i = 0; i < 10; ++i) {
    array_pointers[i] = new node;
    array_pointers[i]->data="null";
    array_pointers[i]->next_node=nullptr;
    }
    return array_pointers;
}
//If a collision occurs a linked list is made with the new input
void complex_hash(string key, node**array){
    int hash_key=make_hash(key);
    
    node**array_pointer=array;
    
    if (array_pointer[hash_key]->data=="null"){
        array_pointer[hash_key]->data=key;
        }
    else{
        node* new_node=new node;
        node* pointer=array_pointer[hash_key];
        while(pointer->next_node!=nullptr){
            pointer=pointer->next_node;
        }
        pointer->next_node=new node;
        pointer->next_node->data=key;
    }
}
//finds key in linked list hashtable
string complex_contains(string key,node**array){
    node**array_pointer=array;
    int hash_key=make_hash(key);
    node*pointer=array_pointer[hash_key];
    if (pointer->data==key){
        cout<<"Value is in hashtable"<<"\n";
    }
    else{
        
        while(pointer->next_node!=nullptr){
            pointer=pointer->next_node;
            if (pointer->data==key){
                cout<<"Value is in hastable"<<"\n";
                return key;
            }
        }
        if (pointer->next_node==nullptr){
            cout<<"Value not found"<<"\n";
            return key;
            }
        
}
}


int main(){
  //In terms of complexity the simply hash should just be O(1) while the complex hash should be O(n) (in the worst case)
    hash_add("bob");
    hash_add("janice");
    
    contains("bob");
    contains("janice");
    contains("jim");

    node**complex_array=create_linked_array();
    
    complex_hash("jim",complex_array);
    complex_hash("bop",complex_array);
    complex_hash("pob",complex_array);
    
    complex_contains("pob",complex_array);
    complex_contains("bop",complex_array);
    complex_contains("jim",complex_array);
}
