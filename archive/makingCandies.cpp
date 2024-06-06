#include<bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long M,W,P,N;
  cin>>M>>W>>P>>N;

  unsigned long long pass=0,rem=0,prod=0,invest=0,td=INT64_MAX,ed=0,sum=0,delta;
  //prod = M * W;
  rem = N;
  if(W >= N/M){
    cout<<1<<endl;
    return 0;
  }
  while(sum < N){
    prod = M*W;
    ed = ceil((long double)(N-sum)/prod);
    td=min(td,pass+ed);
    delta = M-W;
    delta = delta<0?-delta:delta;
    if(sum + prod < P){
      unsigned long long t = (P-sum)/prod - 1 ;
      sum += prod*t;
      pass += t;
    }
    pass++;
    sum += prod;
    if(sum >= N || pass > td)
    break;
    invest = sum / P;
    sum -= invest * P;
    while(invest){
      if(M==W){
        W+=invest/2;
        M+= invest - invest/2;
        invest=0;
      }
      else if(M<W){
        M+=min(delta,invest);
        invest -= min(delta,invest);
      }
      else{
        W+=min(delta,invest);
        invest-=min(delta,invest);
      }
    }
  }
  cout<<min(td,pass)<<endl;
  return 0;
}
