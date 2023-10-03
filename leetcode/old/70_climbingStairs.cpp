#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n){
	int dp[n+1];
	for(int i=0;i<n;++i)
		dp[i]=0;
	//base cond.
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<n+1;++i){
		dp[i]=dp[i-1]+dp[i-2];
	}

	return dp[n];
}

int main(){
	int n;
	cin>>n;
	int res=climbStairs(n);
	cout<<res<<endl;

	return 0;
}
