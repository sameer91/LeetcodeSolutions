#include<iostream>
#include<list>
using namespace std;

struct Node{
  int key;
  Node *left;
  Node *right;
  Node(int x){
    key=x;
    left=NULL;
    right=NULL;
  }
};

void printLeftView(Node *root){
  list<Node *> q;
  q.push_back(root);
  while(!q.empty()){
    list<Node *> temp;
    cout<<q.front()->key<<" ";
    while(!q.empty()){
      Node * itr =q.front();
      q.pop_front();
      if(itr->left != NULL){
        temp.push_back(itr->left);
      }
      if(itr->right != NULL){
        temp.push_back(itr->right);
      }
    }
    q=temp;
  }
  cout <<endl;
}


int main(){
  Node *root=new Node(4);
  root->left=new Node(5);
  root->right=new Node(2);
  root->right->left=new Node(3);
  root->right->right=new Node(1);
  root->right->left->left=new Node(6);
  root->right->left->right=new Node(7);

  printLeftView(root);
  return 0;
}
