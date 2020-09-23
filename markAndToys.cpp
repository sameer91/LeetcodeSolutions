#include <bits/stdc++.h>
using namespace std;


int findMax(long *arr,int n, long k){
  sort(arr, arr+n);
  int count = 0;
  for(int i = 0; i<n;i++){
    if(k<arr[i])
      break;
    k-=arr[i];
    count++;
  }
  return count;

}

int main() {
  long n, k;
  cin >> n>>k;

  long arr[n];
  for(long i=0; i<n;i++){

    cin>>arr[i];
  }
  cout<< findMax(arr,n,k)<<endl;
  return 0;
}
