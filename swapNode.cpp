#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
};

struct node * createNode(int d){
  struct node * ptr=new struct node;
  ptr->data=d;
  ptr->left=NULL;
  ptr->right=NULL;
  return ptr;
}

void addNodes(node *ptr, int left,int right){
  struct node *leftNode = createNode(left);
  struct node *rightNode = createNode(right);

  ptr->left=leftNode;
  ptr->right=rightNode;

  return;
}

struct node* insTarget(struct node* root){
  struct node * t = NULL;
  stack<struct node*> stk, tempStk;
  stk.push(root);
  while(true){
    struct node * tmp = stk.top();
    stk.pop();
    if(tmp->data != -1 && tmp->left == NULL && tmp->right == NULL)
      return tmp;
    if(tmp->data != -1){
      tempStk.push(tmp->left);
      tempStk.push(tmp->right);
    }
    if(stk.empty()){
      while(!tempStk.empty()){
        stk.push(tempStk.top());
        tempStk.pop();
      }
    }
  }
  return NULL;
}

void printTree(struct node * root){
  if(root->left->data != -1)
    printTree(root->left);
  cout<<root->data<<' ';
  if(root->right->data != -1)
    printTree(root->right);
}

void swapChild(struct node * root){
  if(root->data == -1 || (root->left->data == -1 && root->right->data == -1))
    return;
  swapChild(root->left);
  swapChild(root->right);
  struct node * temp = root->left;
  root->left = root->right;
  root->right = temp;
}

void swaplevel(struct node * root, int level){
  stack<struct node *> stk,stk2;
  stk.push(root);
  int l = level;
  while(!stk.empty()){
    struct node * itr;
    if(l==1){
      stk2=stk;
      while(!stk2.empty()){
        struct node * temp,*tl;
        temp = stk2.top();
        stk2.pop();
        if(temp->data == -1)
          continue;
        //    swapChild(temp);
        tl= temp->left;
        temp->left=temp->right;
        temp->right=tl;
      }
      l=level+1;
    }
    while(!stk.empty()){
      itr = stk.top();
      stk.pop();
      if(itr->data == -1)
        continue;
      stk2.push(itr->left);
      stk2.push(itr->right);
    }
    stk=stk2;
    while(!stk2.empty())
      stk2.pop();
    l--;
  }


}


int main() {
  int n = 0;
  cin>>n;
  int k;
  struct node * root=createNode(1);
  struct node * temp;
  vector<int> queries;

  for(int i = 0;i<n;i++){
    int t1,t2;
    cin>>t1>>t2;
    temp = insTarget(root);
    addNodes(temp, t1, t2);
  }

  cin>>k;
  for(int i = 0;i<k;i++){
    int t;
    cin >>t;
    queries.push_back(t);
  }
  printTree(root);
  cout<<endl;

  for(int i=0;i<queries.size();i++){
    int l=queries[i];
    //swap at level
    swaplevel(root, l);
    printTree(root);
    cout<<endl;
  }


  return 0;
}
