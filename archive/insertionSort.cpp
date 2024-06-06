#include<iostream>
using namespace std;
int main(){
  int arr[]={12,21,312,3,123,13,12,31,3,123,3,2,2,34};
  int n=sizeof(arr)/sizeof(int);
  for(int i=1;i<n;i++){
    int j=i-1;
    while(j>=0 && arr[j]>arr[j+1]){
      swap(arr[j],arr[j+1]);
      j--;
    }
  }
  for (int i=0; i<n; ++i) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;

}
