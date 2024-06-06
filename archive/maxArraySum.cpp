#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int> arr, int p){
  if(p == 0)
    return arr[0]<0?0:arr[0];
  if(p == 1)
    return max(arr[0],arr[1])<0?0:max(arr[0],arr[1]);

  return max(maxSum(arr,p-2)+arr[p], maxSum(arr,p-1));
}

int main(){
  int n,k;
  cin>>n;
  vector<int> arr;
  for(int i = 0;i<n;i++){
    cin>>k;
    arr.push_back(k);
  }
  //devide and conqure
  //cout<<maxSum(arr, n-1)<<endl;
  vector<int> dp(n,0);
  dp[0] = arr[0]<0?0:arr[0];
  dp[1] = max(arr[0],arr[1])<0?0:max(arr[0],arr[1]);
  for(int i=2;i<n;i++){
    int temp=0;
    temp = max(dp[i-1],dp[i-2] + arr[i]);
    dp[i] = temp<0?0:temp;
  }
  cout<<dp[n-1]<<endl;
  return 0;

}
