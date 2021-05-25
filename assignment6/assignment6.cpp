#include <iostream>

using namespace std;


struct node{
    int data;
    node *left;
    node *right;
};

void add(node *root,int value){
  node *pointer=root;
  node *new_node= new node();
  new_node->data=value;
  new_node->left=nullptr;
  new_node->right=nullptr;
  bool placed=false;

while (placed==false){
  if (new_node->data<=pointer->data){
      if (pointer->left==nullptr){
          pointer->left=new_node;
          placed=true;
  }
    else{
        pointer=pointer->left;

    }
  }
  else if(new_node->data>pointer->data){
    if (pointer->right==nullptr){
      pointer->right=new_node;
      placed=true;
    }
    else{
      pointer=pointer->right;
    }

  }
}

};

node* find(node *root, int number){
  node* pointer=root;
  node*pointer_trail=root;
  bool found=false;

  while (pointer!=nullptr&&found==false){ 
    if (number<pointer->data){
      pointer_trail=pointer; 
      pointer=pointer->left;
    }
    else if(number>pointer->data){
      pointer_trail=pointer; 
      pointer=pointer->right;
    }
    
    else if (number==pointer->data){
      found=true;
      cout<<"Found and replaced "<<number<<"\n";
      if (pointer->right!=nullptr){
        node *successor=pointer->right;
        node*successor_trail=successor;
        while (successor->left!=nullptr){
          successor_trail=successor; 
          successor=successor->left;
        }
        
        if (number>pointer_trail->data){
          pointer_trail->right=successor;
        }
        else{
          pointer_trail->left=successor;
        }
        successor->left=pointer->left;
        successor->right=pointer->right;
    
        return successor;

      }
      else{
        if(pointer->data<=pointer_trail->data){
          pointer_trail->left=pointer->left;
        }
        else{
          pointer_trail->right=pointer->left;
          
        } 
      }

      
    }
   
    
  }

  if (found==true){
    return pointer;
  }
  else{
    return root;
  }
}

void remove(node *root, int number){
  node *found_node=find(root,number);
}


int main(){
    node *root=new node();
    root->data=10;
    root->left=nullptr;
    root->right=nullptr;

    add(root,9);
    add(root,10);
    cout<<root->left->right->data<<"\n";
    add(root,15);
    add(root,11);
    add(root,18);
    add(root,16);
    find(root,15);
    cout<<root->right->right->data;
}
