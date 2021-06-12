#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 

//I looked into vectors more to improve my code

//nodes struct
struct node{
    int data;
    vector<node*> adjecents;
    vector<int> weights;
    node* parent;
    int value=9999;
    bool visited;
};

//creats the vertices of the graph
node** graph_maxtrix(int number_nodes){
    node** array_pointers = new node*[10];
    for(int i = 0; i < number_nodes; ++i) {
    array_pointers[i] = new node;
    array_pointers[i]->data=i;
    }
    return array_pointers;
}

//creats the edges for a simple graph
void add_edge(int start,int finish,int weight,node** graph){
    node**array_pointer=graph;
    node* end_node=array_pointer[finish];
    array_pointer[start]->adjecents.push_back(end_node);
    array_pointer[start]->weights.push_back(weight);
}
//very simple minimum spanning tree
void MST(node**graph,int number_nodes){
    vector<int> visited;
    int current_number=0;
    int min=9999;
    cout<<"--MST--"<<"\n";
     for(int i=0;i<number_nodes;i++){
        min = *min_element(graph[current_number]->weights.begin(), graph[current_number]->weights.end());
         for(int j=0;j<graph[current_number]->adjecents.size();j++){
             //looks to see if adjecent node is in the visited vector and its edge weight is equal to the minimum value 
             if (find(visited.begin(), visited.end(), graph[current_number]->adjecents[j]->data) != visited.end()==false and 
             (graph[current_number]->weights[j]==min)){
                 visited.push_back(current_number);
                 cout<<current_number<<" --> "<<graph[current_number]->adjecents[j]->data<<"\n";
                 current_number=graph[current_number]->adjecents[j]->data;
                 
                
                 
             }
         }
    }
}


//simple shortest path function it prints the shortest path in reverse.
void shortest_path(int start,int finish,node** graph){
    vector<node*> queue;
    node* current_adjecent;
    //sets starting nodes_distance to itself to be 0
    graph[start]->value=0;
    
    queue.push_back(graph[start]);
    //sets starting nodes parent to be itself
    graph[start]->parent=graph[start];
    //checks if queue is empty
    while(queue.empty()==false){
        for(int j=0;j<queue[0]->adjecents.size();j++){
            current_adjecent=queue[0]->adjecents[j];
            if (current_adjecent->visited==false and (current_adjecent->value>queue[0]->value+queue[0]->weights[j])){
                current_adjecent->visited=true;
                current_adjecent->value=queue[0]->value+queue[0]->weights[j];
                current_adjecent->parent=queue[0];
                queue.push_back(current_adjecent);
                
            }
        }
        queue.erase(queue.begin());
        }
    node* current_node=graph[finish];
    vector<node*>queue2;
    //second queue so results can be printed
    queue2.push_back(graph[finish]);
    cout<<"Shortest path"<<"\n";
    while (current_node->parent!=current_node){
        cout<<current_node->data<<" <-- ";
        current_node=current_node->parent;
        cout<<current_node->data<<"\n";
        queue2.push_back(current_node);

    }
}

int main(){
    //In terms of complexity I belive my vertex and edge adding function is only doing O(1) while I believe that my MST is O(N)
    //The shortest path is also probably O(n).
    node** graph=graph_maxtrix(6);
    add_edge(0,2,2,graph);
    add_edge(0,1,4,graph);
    add_edge(2,5,3,graph);
    add_edge(2,4,6,graph);
    add_edge(4,1,3,graph);
    add_edge(5,4,3,graph);
    
    shortest_path(0,5,graph);
    MST(graph,6);
    
}
