#include<iostream>
using namespace std;

int main() {
  int arr[] = {21,4,2,4,1,4,5,4,4,9,5,67,654,3,2345,98,7,5,2,221,1,3,5,432};
  int n=sizeof(arr)/sizeof(int);
  int f=0,b=n-1;
  while(f<b){
    swap(arr[f],arr[b]);
    ++f;
    --b;
  }
  for (int i=0; i<n; ++i) {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}
