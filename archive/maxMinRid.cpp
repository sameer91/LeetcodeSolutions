#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long> arr;
  arr.push_back(0);
  for(int i=0;i<n;i++){
    long x;
    cin>>x;
    arr.push_back(x);
  }
  arr.push_back(0);
  stack<long> stE,stI;
  map<long,int> maxWin;
  for (int i=0; i<arr.size(); ++i) {
    if(!stE.empty() && stE.top() > arr[i]){
      while(!stE.empty() && stE.top() > arr[i]){
        long no=stE.top();
        stE.pop();
        stI.pop();
        if(!stE.empty())
          maxWin[no]=i-stI.top()-1;
        else
          maxWin[no]=1;
      }
    }
    stE.push(arr[i]);
    stI.push(i);
  }
  map<int,long> rev;
  for(auto i=maxWin.begin();i!=maxWin.end();++i){
    rev[i->second]=i->first;
  }
  auto itr=rev.rbegin();
  long currMax=0;
  int win=n;
  vector<long> ans;
  while(win>0){
    if(itr!= rev.rend() && win==itr->first){
      currMax=itr->second>currMax?itr->second:currMax;
      itr++;
    }
    ans.push_back(currMax);
    win--;
  }
  for (auto i=ans.rbegin(); i!=ans.rend(); ++i) {
    cout<<*i<<' ';
  }
  cout<<endl;
  return 0;
}
