#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int s, int e){
  if(s>=e)
    return;
  int pivot = arr[s];
  int tptr=s;
  for(int i=s+1;i<e;i++){
    if(arr[i]<pivot){
      tptr++;
      swap(arr[tptr],arr[i]);
    }
  }
  swap(arr[s],arr[tptr]);
  quickSort(arr, s, tptr-1);
  quickSort(arr, tptr+1, e);
}

int main() {
  int a[]={3,54,213,213,2,1,4,3,2,23,6,2,3,8};
  int n = sizeof(a)/sizeof(int);

  quickSort(a, 0, n);
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
