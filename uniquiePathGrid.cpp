#include <iostream>
#include<vector>
#include<cmath>
#define MOD 1000000007
#define ll long long

using namespace std;


vector<int> seive(int x){
  int arr[x+1];
  for(int i=0;i<=x;++i)
    arr[i]=i;
  arr[0]=-1;
  arr[1]=-1;
  for(int i=2;i<=x;++i){
    int p=arr[i]*arr[i];
    while (p<=x) {
      arr[p]=arr[i];
      p+=arr[i];
    }
  }
  vector<int> primes;
  for(int i=2;i<=x;++i){
    if(arr[i]==i)
      primes.push_back(arr[i]);
  }
  return primes;
}

int divisor(vector<int> primes,int x,int y){
  auto i=primes.begin();
  int count=1;
  while(*i < max(x,y)){
    int p=*i;
    int c=1;
    while(x%p==0){
      x/=p;
      c++;
    }
    while(y%p==0){
      y/=p;
      c++;
    }
    count *= c;
  }
  if(x==y)
    count*=3;
  else
    count*=2;
  return count;
}

int main() {
  int T;
  cin>>T;
  while(T--){
    int M,N;
    cin>>M>>N;
    int arr[N][M],l=0;
    for(int i=0;i<N;++i){
      for(int j=0;j<M;++j){
        cin>>arr[i][j];
        l = max(l,arr[i][j]);
      }
    }
    l = sqrt(l);
    vector<int> primes=seive(l);
    int dp[N+1][M+1];
    for(int i=0;i<M;++i){
      dp[0][i]=0;
    }
    for(int i=0;i<N;++i){
      dp[i][0]=0;
    }
    dp[0][0]=1;
    for(int i=0;i<N;++i){
      for(int j=0;j<M;++j){
        cout<<dp[i][j]<<' ';
      }
      cout<<endl;
    }

  }
  return 0;
}
