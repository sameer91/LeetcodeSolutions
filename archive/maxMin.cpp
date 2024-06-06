#include<bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin>>n;
  cin>>k;

  int arr[n];
  for(int i = 0;i<n;i++)
	cin>>arr[i];

  sort(arr,arr+n);

  int minFair=INT_MAX;
  for(int i=0;i+k-1<n;i++){
	minFair = min(minFair,arr[i+k-1]-arr[i]);
  }
  cout<<minFair<<endl;

  return 0;
}
