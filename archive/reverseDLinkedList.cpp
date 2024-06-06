#include<iostream>
using namespace std;

struct Node{
  int data;
  Node *next, *prev;
  Node(int data){
    this->data = data;
    next=NULL;
    prev=NULL;
  }
};

Node *insert(Node *head, int data){
  if(head == NULL) return new Node(data);
  if(head->data > data){
    Node *newNode = new Node(data);
    newNode->next=head;
    head->prev=newNode;
    return newNode;
  }
  Node *ptr=head,*prev=head;
  while(ptr!=NULL && ptr->data<data){
    prev=ptr;
    ptr=ptr->next;
  }
  if(ptr==NULL){
    Node *newNode=new Node(data);
    prev->next=newNode;
    newNode->prev=prev;
    return head;
  }

  Node *newNode=new Node(data);
  prev->next=newNode;
  newNode->next=ptr;
  ptr->prev=newNode;
  newNode->prev=prev;
  return head;
}

Node *reverse(Node *head){
  Node *itr=head,*n=NULL,*p=NULL;
  while(itr!=NULL){
    n=itr->next,p=itr->prev;
    itr->next=p;
    itr->prev=n;
    p=itr;
    itr=n;
  }
  return p;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    Node *head=NULL;
    int N,d;
    cin>>N;
    for(int i=0;i<N;++i){
      cin>>d;
      head =  insert(head,d);
    }
    //reverse
    head = reverse(head);
    while(head!=NULL){
      cout<<head->data<<' ';
      head=head->next;
    }
    cout<<endl;
  }
  return 0;
}
