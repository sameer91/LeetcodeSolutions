#include<bits/stdc++.h>
using namespace std;

long mergeArr(vector<long> &arr, long i, long mid, long j){
  long count=0, p1=0,p2=mid+1;
  for(p1 = i;p1<=mid;p1++){
    if(arr[p1] > arr[p2])
      break;
  }
  long t1=p1;
  vector<long> mrg(j-t1, 0);
  while(p1 < p2 && p1<mid+1 && p2<j+1){
    if(arr[p1]<=arr[p2]){
      mrg.push_back(arr[p1]);
      p1++;
    }
    else {
      mrg.push_back(arr[p2]);
      count += p2-p1;
      p2++;
    }
  }
  for(;p1<mid+1;p1++){
    mrg.push_back(arr[p1]);
  }
  for(;p2<j+1;p2++){
    mrg.push_back(arr[p2]);
  }
  for(int i = 0; i<j-t1;i++){
    arr[t1+i] = mrg[i];
  }
  return count;
}


long mergeSort(vector<long> &arr, long i,long j){
  if(i==j)
    return 0;
  long mid = (i+j)/2;
  long count = mergeSort(arr, i, mid) + mergeSort(arr, mid+1,j);
  return mergeArr(arr, i, mid, j) + count;
}


int main() {
  int d = 0;
  cin>>d;
  while(d--){
    long n = 0;
    cin>>n;
    vector<long> arr(n,0);
    for(int i = 0;i<n;i++){
      cin>>arr[i];
    }

    cout << mergeSort(arr,0,n-1)<<endl;
  }
  return 0;
}
