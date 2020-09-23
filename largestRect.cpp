#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> h;
  stack<int> stkE,stkI;
  int run=0;
  h.push_back(0);
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    h.push_back(x);
  }
  h.push_back(0);
  int M=0;
  for(int i=0;i<h.size();i++){
    if(!stkE.empty() && stkE.top() > h[i]){
      int temp=0,e=0;
      while(!stkE.empty()&&stkE.top() > h[i]){
        e=stkE.top();
        stkE.pop();
        stkI.pop();
        if(!stkE.empty())
          temp=(i-stkI.top()-1)*e;
        else
          temp=e;
        M=max(M,temp);
      }
    }
    stkE.push(h[i]);
    stkI.push(i);
  }
  cout<<M<<endl;
  return 0;
}
