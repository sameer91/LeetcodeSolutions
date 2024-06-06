#include<iostream>
using namespace std;

struct Node{
  int key;
  Node *next;
  Node(int k){
    key=k;
    next=NULL;
  }
};

void insert(Node **root,int x){
  if(*root == NULL){
    *root = new Node(x);
    return;
  }
  insert(&(*root)->next,x);
}

void midElement(Node *root){
  Node *slow=root,*fast=root;
  while(fast!=NULL && fast->next != NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  cout<<slow->key<<endl;
}

int main(){
  Node *root=NULL;
  insert(&root,1);
  insert(&root,2);
  insert(&root,3);
  insert(&root,4);
  insert(&root,5);
  insert(&root,6);
  midElement(root);
  return 0;

}
