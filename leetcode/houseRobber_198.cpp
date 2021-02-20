#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums){
	int N=nums.size();
	vector<vector<int>> dp(N,vector<int>(2,0));
	dp[0][1]=nums[0];
	dp[1][0]=nums[0];
	dp[1][1]=nums[1];
	for(int i=2;i<N;++i){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=max(dp[i-2][0],dp[i-2][1])+nums[i];
	}
	return max(dp[N-1][0],dp[N-1][1]);
}

int main(){
	int N;
	cin>>N;
	vector<int> nums(N,0);
	for(int i=0;i<N;++i)
		cin>>nums[i];
	int res = rob(nums);
	cout<<res<<endl;

	return 0;
}
