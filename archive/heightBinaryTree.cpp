#include<iostream>

using namespace std;

struct Node{
  int Key;
  Node *left;
  Node *right;
  Node(int k){
    Key=k;
    left=NULL;
    right=NULL;
  }
};

Node* insert(Node *root, int k){
  if(root == NULL){
    return new Node(k);
  }
  else {
    if(k < root->Key){
      Node *curr = insert(root->left,k);
      root->left = curr;
    }
    else {
      Node *curr = insert(root->right,k);
      root->right = curr;
    }
  }
  return root;
}

int treeHeight(Node *root){
  if(root == NULL)
    return 0;
  else {
    return 1+max(treeHeight(root->left),treeHeight(root->right));
  }
}

int main(){
  Node *root = NULL;
  int N;
  cin>>N;
  while(N--){
    int k;
    cin>>k;
    root = insert(root,k);
  }
  cout<<treeHeight(root)-1<<endl;
  return 0;
}
