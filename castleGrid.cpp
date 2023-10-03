#include<bits/stdc++.h>
using namespace std;

int main(){
  int the;
  int n;
  cin>>n;
  vector<vector<char>> grid(n,vector<char>(n,'.'));
  for (int i=0; i<n; ++i) {
    for (int j=0; j < n; ++j) {
      char ch;
      cin>>ch;
      if(ch=='X')
        grid[i][j]='X';
    }
  }
  int x1,x2,y1,y2;
  cin>>x1>>y1>>x2>>y2;



}
