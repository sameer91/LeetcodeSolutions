#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >>n>>k;
  int arr[n];
  map<int,int> indices,freq;
  for(int i =0;i<n;i++){
    cin>>arr[i];
    indices[arr[i]] = i;
    freq[arr[i]]++;
  }
  int count=0;
  for(int i = 0;i<n;i++){
    int a = arr[i],b;
    b = k+a;
    if(freq[b] != 0){
      count+=freq[b];
    }
  }
  cout<<count<<endl;
  return 0;
}
