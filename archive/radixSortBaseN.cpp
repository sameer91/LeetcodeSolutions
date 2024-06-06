#include<iostream>
#include<vector>
using namespace std;

void countSort(int arr[],int baseN[],int N, int exp){
  int count[10]={0};
  int op[N],baseNop[N];
  for(int i=0;i<N;++i){
    count[(baseN[i]/exp)%10]++;
    op[i]=0;
    baseNop[i]=0;
  }
  for(int i=1;i<10;++i){
    count[i]+=count[i-1];
  }
  for(int i=N-1;i>=0;--i){
    op[count[ (baseN[i]/exp)%10]-1]=arr[i];
    baseNop[count[ (baseN[i]/exp)%10]-1]=baseN[i];
    count[(baseN[i]/exp)%10]--;
  }
  for(int i=0;i<N;++i){
    arr[i]=op[i];
    baseN[i]=baseNop[i];
  }
}

int main(){
  int N;
  cin>>N;
  int arr[N];
  int baseN[N];
  for(int i=0;i<N;++i){
    cin>>arr[i];
    baseN[i]=0;
  }
  for(int i=0;i<N;++i){
    int n=arr[i],exp=N,dec=1;
    while(n>0){
      baseN[i]+=(n%exp)*dec;
      n=n/exp;
      exp*=exp;
      dec*=10;
    }
  }
  countSort(arr, baseN, N, 1);
  countSort(arr, baseN, N, 10);
  for(int i=0;i<N;++i){
    cout<<arr[i]<<' ';
  }
  cout<<endl;
  return 0;
}
