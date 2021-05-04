#include <iostream>

using namespace std;


struct node{
    int data;
    node *next_node;
};

//link to code I looked at to better understand c++ for loop
//https://www.w3schools.com/cpp/cpp_for_loop.asp


//adds new data node at give position
void add_value(node* header,int value, int position)
{
  node *pointer=header;
  node *new_node= new node();
  new_node->data=value;
  new_node->next_node=nullptr;

  position--;

  while(position !=1)
  {
    pointer=pointer->next_node;
    position--;
  }
  new_node->next_node=pointer->next_node;
  pointer->next_node=new_node;
}
//removes and returns data of node a given point
int remove(node* header,int position){
    node* temp_point=header;
    int removed_data;
    int interable;
    
    for (interable=0; interable<position-2;interable++)
        temp_point=temp_point->next_node;
    node* temp_point2=temp_point->next_node;
    temp_point->next_node=temp_point2->next_node;
    removed_data=temp_point2->data;
    delete temp_point2;
    
    return removed_data;
}

//looks at data of node at given position
void look(node* header,int position)
{
    node *pointer= header;
    
    if (position==1){
        cout<<pointer->data;
    }
    else{
        while(position!=1)
        {
            pointer=pointer->next_node;
            position--;
            if (position==1){
            cout<<pointer->data;
            }
        }
    }

}

int main(){
    node *header=new node();
    header->data=10;
    header->next_node=NULL;

    add_value(header,3,2);
    add_value(header,7,3);
    add_value(header,5,4);
    
    remove(header,2);
    //should print 3
    look(header,2);
}