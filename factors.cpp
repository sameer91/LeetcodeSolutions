#include<iostream>
#include<math.h>
#include<list>
using namespace std;

list<int> sieve(int N){
  int sieve[N+1];
  for(int i=0;i<=N;++i){
    sieve[i]=i;
  }
  for(int i=2;i<=N;++i){
    if(sieve[i]==i){
      int itr=sieve[i]*sieve[i];
      while(itr<=N){
        sieve[itr]=sieve[i];
        itr+=sieve[i];
      }
    }
  }
  list<int> primes;
  for(int i=2;i<=N;++i){
    primes.push_back(sieve[i]);
  }
  return primes;
}
int main(){
  int N;
  cin>>N;
  int s=sqrt(N);
  list<int> primes=sieve(s);
  int count=1,d;
  list<int>::iterator itr=primes.begin();
  d=N;
  for(;itr!=primes.end();++itr){
    int p=*itr,c=1;
    while(d!=1 && d%p == 0){
      c++;
      d/=p;
    }
    count *=c;
  }
  if(d>1)
    count *=2;
  cout<<count<<endl;
  return 0;
}
