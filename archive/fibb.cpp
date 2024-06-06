#include<iostream>
using namespace std;

int main(){
  int p2=1,p=1;
  int N=10;
  cout<<p2<<' '<<p<<' ';
  N-=2;
  while(N--){
    p += p2;
    p2=p-p2;
    cout<<p<<' ';
  }
  cout<<endl;
  return 0;
}
