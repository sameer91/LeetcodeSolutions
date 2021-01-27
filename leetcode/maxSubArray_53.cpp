#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &num){
	//Solve
	int N=num.size();
	vector<int> dp(N,0);
	dp[0]=num[0];

	for(int i=1;i<N;++i){
		dp[i]=max(num[i], dp[i-1]+num[i]);
	}
	int maxSum=dp[0];
	for(int i=1;i<N;++i){
		if(maxSum<dp[i])
			maxSum=dp[i];
	}
	return maxSum;
}

int main(){
	int N;
	cin>>N;
	vector<int> num(N,0);
	for(int i=0;i<N;++i){
		cin>>num[i];
	}
	int res = maxSubArray(num);
	cout<<res<<endl;
	return 0;
}
