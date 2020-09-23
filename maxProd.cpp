#include<iostream>
using namespace std;

int main(){
  int arr[]={2,-4,-9,12,5,2,0,-16,24};
  int maxPos=0,maxPos2=0,maxPos3=0;
  int min=0,min2=0, n=sizeof(arr)/sizeof(int);
  for(int i=0;i<n;i++){
    if(arr[i] > 0){
      if(arr[i] > maxPos){
        maxPos3=maxPos2;
        maxPos2=maxPos;
        maxPos=arr[i];
      }
      else if(arr[i]>maxPos2){
        maxPos3=maxPos2;
        maxPos2=arr[i];
      }
      else if(arr[i]>maxPos3){
        maxPos3=arr[i];
      }
    }
    else {
      if(arr[i]<min){
        min2=min;
        min=arr[i];
      }
      else if(arr[i]<min2){
        min2=arr[i];
      }
    }
  }
  cout << max(maxPos*maxPos2*maxPos3,min*min2*maxPos)<<endl;
  return 0;
}
