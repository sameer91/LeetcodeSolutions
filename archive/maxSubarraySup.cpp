#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long m;
  int q;
  cin>>q;
  while(q--){
    cin >> n >> m;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    long long s=0,mx=0;
    set<long long> pre;
    for(int i =0;i<n;i++){
      s = (s+arr[i])%m;
      mx=max(s,mx);
      auto itr= pre.upper_bound(s);
      if(itr!=pre.end()){
        mx = max(mx,s-*itr + m);
      }
      pre.insert(s);
    }
    cout<<mx<<endl;
  }
  return 0;
}
