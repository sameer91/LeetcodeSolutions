#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,goal;
  cin>>n>>goal;

  int machines[n];
  map<int,int> freq;
  for(int i = 0;i<n;i++){
    cin>>machines[i];
    freq[machines[i]]++;
  }
  // int rem=goal,day=0,min=*min_element(machines,machines+n);
  // while(rem>0){
  //   day+=1;
  //   for(auto i = freq.begin();i!=freq.end();i++){
  //     if(day%i->first == 0)
  //       rem-=i->second;
  //   }
  // }
  //binary search
  int totalPossible=0,start=1,end=1000000000;
  int mid = end;
  while(totalPossible != goal && start!=end){
    int temp=0;
    totalPossible = 0;
    for(auto i = freq.begin();i!=freq.end();i++){
      int round = mid/i->first;
      totalPossible += round*i->second;
      temp = max(temp,round*i->first);
    }
    mid = temp;
    if(goal < totalPossible){
      end=mid;
    } else if(totalPossible < goal){
      start = mid;
    }
    mid = (start+end)/2;
  }

  cout<<mid<<endl;

  return 0;
}
