#include<iostream>
using namespace std;

int main(){
  int N;
  cin>>N;
  int E=N-1;
  int count=0;
  if(E==1)
    count = 3;
  else{
    count = 4*(E-2)+2*3;
  }
  cout << count<<endl;
  return 0;

}
