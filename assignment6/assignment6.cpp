#include <iostream>

using namespace std;


//I did some reaserch on recusion to get the tree traversal working
//link to site https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm

struct node{
    int data;
    node *left;
    node *right;
};

//Adds node to binary tree with inputed value
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

//Finds successor in an inorder manner and removes node with inputed value 
node* remove(node *root, int number){
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
    //node is found
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
//traverses tree using the inorder recusive meathod 
node * inorder_tranverse(node*root){
  node* pointer=root;
  if (pointer==nullptr) return pointer;
  inorder_tranverse(pointer->left);
  cout<<pointer->data<<"\n";
  inorder_tranverse(pointer->right); 

}

//main
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
    inorder_tranverse(root);
    remove(root,15);
    cout<<root->right->right->data;
    
}
