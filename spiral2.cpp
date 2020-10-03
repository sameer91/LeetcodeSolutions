#include<iostream>
#include<vector>
using namespace std;

void printUtil(vector<vector<int>> mat,int CR ,int s,int e,char dir){
  if(s<0 || e<0)
    return;
  if(dir == 'C' && (s>=mat.size() || e>=mat.size()))
    return;
  if(dir == 'R' && (s>=mat[0].size() || e>=mat[0].size()))
    return;

  int mod=0;
  if(s==e){
    if(dir == 'C' && mat[s][CR]!=-1){
      cout<<mat[s][CR]<<' ';
      mat[s][CR]=-1;
    }
    else if(mat[CR][s]!=-1){
      cout<<mat[CR][s];
      mat[CR][s]=-1;
     }
    return;
  }
  if(s<e)
    mod=1;
  else
    mod=-1;

  if(dir == 'C'){
    for(int i=s;i!=e+mod;i+=mod){
      cout<<mat[i][CR]<<' ';
      mat[i][CR]=-1;
    }
  }
  else {
    for(int i=s;i!=e+mod;i+=mod){
      cout<<mat[CR][i]<<' ';
      mat[CR][i]=-1;
    }
  }
}

void traverse(vector<vector<int>> mat,int x1,int y1,int x2,int y2){
  if(x1>x2 || y1>y2)
    return;
  if(x1==x2 && y1==y2){
    printUtil(mat, x1, x2, y1, 'C');
    return;
  }

  printUtil(mat, x1, y1, y2, 'R');
  printUtil(mat, y2, x1+1, x2, 'C');
  printUtil(mat, x2, y2-1, y1, 'R');
  printUtil(mat, y1, x2-1, x1+1, 'C');
  traverse(mat, x1+1, y1+1, x2-1, y2-1);
}

int main(){
  int M,N;
  cin>>M>>N;
  vector<vector<int>> mat(M);
  for(int i=0;i<M;++i)
    mat[i]=vector<int>(N);
  for(int i=0;i<M;++i){
    for(int j=0;j<N;++j){
      cin>>mat[i][j];
   }
  }
  traverse(mat,0,0,M-1,N-1);
  return 0;
}
