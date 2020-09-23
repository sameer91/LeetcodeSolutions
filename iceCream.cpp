#include<bits/stdc++.h>
using namespace std;

int main() {
  int t =0;
  cin >> t;
  while(t--){
    int money=0,n=0,p=0;
    cin >>money>>n;
    map<int,int> freq;
    int price[n];
    for(int i = 0;i<n;i++){
      cin>>p;
      price[i]=p;
      freq[p]++;
    }
    int a1=0,a2=0;
    for(auto i=freq.begin();i!=freq.end();i++){
      int p=i->first,q=money-i->first;
      if(p==q && i->second > 1){
        a1=p;a2=q;
        break;
      }
      else {
        if(freq.find(q)!=freq.end()){
          a1=p;a2=q;
          break;
        }
      }
    }
    for(int i = 0;i<n;i++){
      if(price[i] == a1 || price[i] == a2)
        cout<<i+1<< ' ';
    }
    cout<<endl;
  }
  return 0;
}
