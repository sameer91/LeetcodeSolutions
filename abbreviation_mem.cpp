#include<bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin>>q;
  while(q--){
    string a,b;
    cin>>a;
    cin>>b;
    int m = a.size(),n=b.size();
    vector <vector<bool>> dp(m+1,vector<bool>(n+1));
    dp[0][0] =true;
    for (int i=1; i<=m && islower(a[i-1]); i++) {
      dp[i][0]=true;
    }
    for(int i=1;i<=m;i++){
      for(int j=1;j<=min(i,n);j++){
        if(islower(a[i-1])){
          if(toupper(a[i-1]) == b[j-1])
            dp[i][j] = dp[i-1][j-1] || dp[i-1][j];
          else
            dp[i][j] = dp[i-1][j];
        }
        else {
          if(a[i-1] == b[j-1]){
            dp[i][j] = dp[i-1][j-1];
          }
        }
      }
    }
    if(dp[m][n])
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

  }
  return 0;
}
