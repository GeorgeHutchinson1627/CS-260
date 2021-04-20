#include <iostream>

using namespace std;



//Link to website I looked at to better understand the arrow operator.
//https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/




struct node{
    int data;
    node *next_node;
};
node *front=nullptr;
node *back=nullptr;



//adds node to end of queue
void enqueue(int value)
{
    node *new_node= new node();
    new_node->data=value;
    new_node->next_node=nullptr;
    
    if (front==nullptr)
    {
    front=new_node;
    back=new_node;
    }
    else
    {
    back->next_node=new_node;
    back=new_node;

    }
}


//removes and returns node at the beginning
int dequeue(){
    int removed_data;
    node* new_node= front;
    removed_data=front->data;
    front=front->next_node;
    return removed_data;
}

//peeks at front node
void peek(){
    int front_value;
    front_value=front->data;
    cout << front_value<<"\n";
}

int main()
{
enqueue(2);
enqueue(3);
enqueue(5);
enqueue(6);
peek();
cout<< dequeue()<<"\n";
cout <<dequeue()<<"\n";
cout<< dequeue()<<"\n";

return 0;
}
