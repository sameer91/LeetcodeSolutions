#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[],int N, int exp){
  int count[10];
  for (int i=0; i < 10; ++i) {
    count[i]=0;
  }

  for(int i=0;i<N;++i){
    count[(arr[i]/exp)%10]++;
  }
  for(int i=1;i<10;++i){
    count[i]+=count[i-1];
  }
  int op[N];
  for(int i=N-1;i>=0;--i){
    op[count[(arr[i]/exp)%10]-1]=arr[i];
    count[(arr[i]/exp)%10]--;
  }
  for(int i=0;i<N;++i)
    arr[i]=op[i];
}

void radixSort(int arr[],int N){
  int m=*max_element(arr,arr+N);
  for(int exp=1;m/exp>0;exp*=10){
    countSort(arr,N,exp);
  }
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
