#include<iostream>
#include<algorithm>
using namespace std;

void countSort(int arr[], int N, int exp){
  int count[N];
  int op[N];
  for(int i=0;i<N;++i){
    count[i]=0;
    op[i]=0;
  }
  for(int i=0;i<N;++i){
    count[ (arr[i]/exp)%N ]++;
  }
  for(int i=1;i<N;++i){
    count[i]+=count[i-1];
  }
  for(int i=N-1;i>=0;i--){
    op[count[(arr[i]/exp)%N] - 1]=arr[i];
    count[(arr[i]/exp)%N]--;
  }
  for(int i=0;i<N;++i){
    arr[i]=op[i];
  }
}

void radixSort(int arr[],int N){
  int m = *max_element(arr,arr+N);
  int base = N;
  for(int i=1;m/i>0;i*=base)
    countSort(arr,N,i);
}

int main(){
  int N;
  cin>>N;
  int arr[N];
  for(int i=0;i<N;++i){
    cin>>arr[i];
  }
  radixSort(arr, N);
  for(int i=0;i<N;++i){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
  return 0;
}
