#include<bits/stdc++.h>

using namespace std;

int main() {
  int n,k;
  cin>>n;
  cin>>k;
  int price[n];
  for(int i = 0; i<n;i++)
    cin>>price[i];

  int bCounter=0,totalCost=0;

  sort(price, price + n);
  for(int i=n-1;i>=0;){
    int j = 0;
    while(i>=0 && j<k){
      cout<<price[i]<<' ';
      totalCost+= (bCounter+1)*price[i];
      j++;
      i--;
    }
    cout<<endl;
    bCounter++;
  }
  cout<<totalCost<<endl;

  return 0;
}
