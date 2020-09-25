#include<iostream>
using namespace std;
struct Node{
  int key;
  Node *left;
  Node *right;
  Node(int k){
    key=k;
    right=NULL;
    left=NULL;
  }
};

Node *insert(Node *root, int k){
  if(root==NULL){
    return new Node(k);
  }
  else {
    if(k<root->key){
      Node *c=insert(root->left,k);
      root->left=c;
    }
    else {
      Node *c=insert(root->right,k);
      root->right=c;
    }
    return root;
  }
}

Node *lca(Node *root, int u,int v){
  if(root==NULL){
    return NULL;
  }
  else {
    if(root->key==u||root->key==v)
      return root;
    Node *cr=NULL,*cl=NULL;
    if(u<root->key && v<root->key){
      return lca(root->left,u,v);
    }
    if(u>root->key&&v>root->key){
      return lca(root->right,u,v);
    }
    return root;
  }
}


int main(){
  int N;
  cin>>N;
  Node *root=NULL;
  while(N--){
    int k;
    cin>>k;
    root=insert(root,k);
  }
  Node *lcaNode=NULL;
  int u,v;
  cin>>u>>v;
  lcaNode=lca(root,u,v);
  if(lcaNode){
    cout<<lcaNode->key<<endl;
  }
  //
  return 0;
}
