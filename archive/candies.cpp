#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> arr(n,0);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int> candies(n,1);
  for (int i=1; i<n; ++i) {
    if(arr[i-1]<arr[i])
      candies[i]=candies[i-1]+1;
  }
  for(int i=n-1;i>0;i--){
    if(arr[i-1]>arr[i])
      candies[i-1]=max(candies[i-1],candies[i]+1);
  }
  long long sum=0;
  for(int i=0;i<n;i++)
    sum+=candies[i];
  cout<<sum<<endl;
  return 0;

}
