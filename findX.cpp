#include<iostream>
#include<list>
#include<math.h>
using namespace std;

void populate(int arr[], int len){
  int sieve[len];
  sieve[0]=-1;
  sieve[1]=-1;
  for(int i=2;i<len;++i){
    sieve[i]=i;
  }
  for(int i=2;i<=len/2;++i){
    if(sieve[i]!=-1){
      int itr=2*sieve[i];
      while(itr<=len){
        sieve[itr]=-1;
        itr+=sieve[i];
      }
    }
  }
  for(int i=0;i<len;++i){
    arr[i]=sieve[i];
  }
}

int factors(int X,list<int> primes){
  list<int>::iterator itr;
  itr=primes.begin();
  int count=0,s=sqrt(X);
  while(itr != primes.end() && *itr <= s){
    if(X%*itr == 0)
      count++;
    itr++;
  }
  return count;
}

int main(){
  int N;
  cin>>N;
  int prime[N-1];
  populate(prime,N-1);
  list<int> primes;
  for(int i=0;i<N-1;++i){
    if(prime[i]!=-1)
      primes.push_back(prime[i]);
  }
  for(auto itr=primes.begin();itr!=primes.end();++itr)
    cout<<*itr<<' ';
  cout<<endl;
  int X=1;

  for (int i = 1; i <=N;++i){
    X+= factors(i,primes);
    if(X>=N){
      cout<<i<<endl;
      break;
    }
  }
  return 0;

}
