#include<iostream>
using namespace std;
struct Node{
  int data;
  Node *next;
  Node *prev;
  Node(int data){
    this->data=data;
    next=NULL;
    prev=NULL;
  }
};

Node *insert(Node *head,int data){
  if(head == NULL)
    return new Node(data);
  if(head->data > data){
    Node *newNode = new Node(data);
    newNode->next=head;
    head->prev=newNode;
    return newNode;
  }
  Node *ptr=head, *prev=head;
  while(ptr!= NULL && ptr->data < data){
    prev=ptr;
    ptr=ptr->next;
  }
  if(ptr == NULL){
    Node *newNode=new Node(data);
    prev->next=newNode;
    newNode->prev=prev;
    return head;
  }
  Node *newNode=new Node(data);
  newNode->next=ptr;
  prev->next=newNode;
  newNode->prev=prev;
  ptr->prev=newNode;
  return head;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    Node *root=NULL;
    int N,d;
    cin>>N;
    for(int i=0;i<N;++i){
      cin>>d;
      //insert
      root=insert(root,d);
    }
    Node *ptr=root;
    while(ptr!=NULL){
      cout<<ptr->data<<' ';
      ptr=ptr->next;
    }
    cout<<endl;
  }

  return 0;
}
