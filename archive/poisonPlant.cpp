#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> arr(N,0);
  for(int i=0;i<N;i++){
    cin>>arr[i];
  }
  //arr.push_back(0);
  //arr.insert(arr.begin(), 0);
  stack<int> stk,stkD;
  int maxDaysAlive=0;
  map<int,int> win;
  for(int i=0;i<arr.size();i++){
    int daysAlive=0;
    while(!stk.empty() && stk.top() >= arr[i]){
      daysAlive =max(daysAlive,stkD.top());
      stk.pop();
      stkD.pop();
    }
    if(stk.empty())
      daysAlive=0;
    else
      daysAlive++;

    maxDaysAlive=max(maxDaysAlive,daysAlive);

    stk.push(arr[i]);
    stkD.push(daysAlive);
  }
  // map<int,vector<int>> rev;
  // int maxSteps=0;
  // for(auto i=win.begin();i!=win.end();i++){
  //   rev[i->second].push_back(i->first);
  // }
  // map<int,pair<int,int>> mStep;
  // for(auto i=rev.begin();i!=rev.end();i++){
  //   int w=i->first;
  //   vector<int> idx=i->second;
  //   for(int j=0;j<idx.size();j++){
  //     if(w==0)
  //       mStep[idx[j]]=pair<int,int>(0,0);
  //     else if(w==1) {
  //       mStep[idx[j]]=pair<int,int>(1,1);
  //     }
  //     else {
  //       int k=1;
  //       while(k<w && win[idx[j] + k] == 0)
  //         k++;
  //       mStep[idx[j]].second=mStep[idx[j]+k].second+1;
  //       mStep[idx[j]].first=max(mStep[idx[j]+k].first,w-mStep[idx[j]+k].first);
  //     }
  //   }
  // }
  cout<<"H"<<endl;
  return 0;
}
