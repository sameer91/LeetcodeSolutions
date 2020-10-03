#include<iostream>
#include<vector>
using namespace std;

void traverse(vector<vector<int>> mat, int m,int n){
  int p=0,q=0,r=m,s=n;
  while(p<r && q<s){
    for(int i=q;i<s;i++){
      cout<<mat[p][i]<<' ';
    }
    p++;
    for(int i=p;i<r;i++){
      cout<<mat[i][s-1]<<' ';
    }
    s--;
    for(int i=s-1;i>=q;i--){
      cout<<mat[r-1][i]<<' ';
    }
    r--;
    for(int i=r-1;i>=p;i--){
      cout<<mat[i][q]<<' ';
    }
    q++;
  }
  cout<<endl;
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
  traverse(mat,M,N);
  return 0;
}
