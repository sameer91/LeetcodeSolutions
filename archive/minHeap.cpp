#include<iostream>
#include<cstring>
using namespace std;

void heapify(int arr[],int x,int N){
  int largest=x;
  int l=2*x+1;
  int r=2*x+2;

  if(l<N && arr[l]>arr[largest])
    largest=l;
  if(r<N && arr[r]>arr[largest])
    largest=r;
  if(x!=largest){
    swap(arr[x],arr[largest]);
    heapify(arr,largest,N);
  }
}

void heapSort(int arr[],int N){
  for(int i=N/2-1;i>=0;--i){
    heapify(arr,i,N);
  }
  for(int i=N-1;i>0;--i){
    swap(arr[i],arr[0]);
    heapify(arr,0,i);
  }
}

int main(){
  int N;
  cin>>N;
  int arr[N];
  for(int i=0;i<N;++i){
    cin>>arr[i];
  }
  heapSort(arr,N);
  for(int i=0;i<N;++i){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
  return 0;
}
