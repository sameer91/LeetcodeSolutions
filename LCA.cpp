#include<iostream>
#include <list>
#include <vector>

using namespace std;

struct node{
  int key=0;
  struct node *left ;
  struct node *right;
  node(int x){
	key = x;
	left=NULL;
	right=NULL;
  }
};

void insert(node *root,int x){
  if(root == NULL) {
	root = new node(x);
	return;
  }

  // if(x < root->key){
  //   root->left = insert(root->left,x);
  // }
  // else{
  //   root->right= insert(root->right,x);
  // }
  // return root;
  list<node *> queue;
  std::vector<uint32_t> test;
  queue.push_back(root);
  while(!queue.empty()){
	list<node *> temp;
	while(!queue.empty()){
	  node * ptr = queue.front();
	  queue.pop_front();
	  if(ptr->left != NULL)
		temp.push_back(ptr->left);
	  else {
		ptr->left = new node(x);
		return;
	  }
	  if(ptr->right != NULL)
		temp.push_back(ptr->right);
	  else{
		ptr->right = new node(x);
		return;
	  }
	}
	queue = temp;
  }
}

node *findNode(node *root, int k){
  if(root == NULL)
	return NULL;
  if(root->key == k)
	return root;
  if(k < root->key){
	return findNode(root->left, k);
  }
  else {
	return findNode(root->right, k);
  }
}

node *LCA(node *root, int k1,int k2){
  if(root==NULL)
	return NULL;
  if(root->key==k1 || root->key==k2)
	return root;
  else {
	if(findNode(root->left, k1)){
	  if(findNode(root->right, k2))
		return root;
	  else
		return LCA(root->left,k1,k2);
	}
	else {
	  if(findNode(root->left, k2))
		return root;
	  else
		return LCA(root->right,k1,k2);
	}
  }
  return NULL;
}


int main() {
  node *root=new node(20);
  //   insert(root,20);
   insert(root,8);
   insert(root,22);
   insert(root,4);
   insert(root,12);
   insert(root,10);
   insert(root,14);

  node *lca = LCA(root,10,8);
  cout<<lca->key<<endl;
  return 0;
}
