#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int k){
    data=k;
    next=NULL;
  }
};

void insert(Node **root,int data,int pos=-1){
  Node *temp=*root;
  if(pos==-1){
    if(temp==NULL){
      *root=new Node(data);
      return ;
    }
    while(temp->next != NULL)
      temp=temp->next;
  }
  else {
    //ins at pos
    if(pos==0){
      Node *newroot=new Node(data);
      newroot->next=*root;
      *root=newroot;
      return;
    }
    while(pos>1){
      temp=temp->next;
      pos--;
    }
  }
  Node *add=new Node(data);
  add->next=temp->next;
  temp->next=add;
}

int main(){
  Node *root = NULL;
  int N,data;
  cin>>N;
  for(int i=0;i<N;++i){
    cin>>data;
    insert(&root,data);
  }
  int pos;
  cin>>data;
  cin>>pos;
  insert(&root,data,pos);
  Node *temp=root;
  while(temp!=NULL){
    cout<<temp->data<<' ';
    temp=temp->next;
  }
  cout<<endl;
  return 0;
}
