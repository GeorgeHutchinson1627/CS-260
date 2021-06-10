#include <iostream>
#include <vector>
using namespace std;
 
//nodes only given the possibility of two neighbors
struct node{
    int data;
    node*next_node;
    node*second_node;
    int weight=9999;
    int second_weight=9999;
};

//creats the vertices of the graph
node** graph_maxtrix(int number_nodes){
    node** array_pointers = new node*[10];
    for(int i = 0; i < number_nodes; ++i) {
    array_pointers[i] = new node;
    array_pointers[i]->data=i;
    array_pointers[i]->next_node=nullptr;
    }
    return array_pointers;
}

//creats the edges for a simple graph
void add_edge(int start,int finish,int weight,node** graph){
    node**array_pointer=graph;
    
    node* end_node=array_pointer[finish];
    if (array_pointer[start]->next_node==nullptr){
        array_pointer[start]->next_node=end_node;
        array_pointer[start]->weight=weight;
    }
    else{
        array_pointer[start]->second_node=end_node;
        array_pointer[start]->second_weight=weight;
    }
    
}
//very simple minimum spanning tree
void MST(node**graph,int number_nodes){
    node**array_pointer=graph;
    for(int i=0;i<number_nodes;i++){
        int first_value=array_pointer[i]->weight;
        int second_value=array_pointer[i]->second_weight;
        
        if (first_value<second_value){
            cout<<array_pointer[i]->data<<" --> "<<array_pointer[i]->next_node->data<<"\n";
        }
        else if(first_value>second_value){
            cout<<array_pointer[i]->data<<" --> "<<array_pointer[i]->second_node->data<<"\n";
        }
    }
}


void shortest_path(){

}

int main(){
 //In terms of complexity I belive my vertex and edge adding function is only doing O(1) while I believe that my MST is O(N)
    node** graph=graph_maxtrix(6);
    add_edge(0,2,2,graph);
    add_edge(0,3,5,graph);
    add_edge(1,2,9,graph);
    add_edge(1,3,3,graph);
    add_edge(2,4,6,graph);
    add_edge(2,5,7,graph);
    
    cout<<graph[0]->next_node->data<<"\n";
    cout<<graph[0]->second_node->data<<"\n";
    MST(graph,6);
}
