#include <iostream>
#include <vector>
using namespace std;

int maxCoin(vector<int> &nums){
	int N=nums.size();
	vector<int> values(N+2,0);
	for(int i=1;i<N+1;++i){
		values[i] = nums[i-1];
	}
	values[0]=1;
	values[N+1]=1;
	N = values.size();
	int dp[N][N];
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			dp[i][j]=0;

	for(int k=2;k<N;++k){
		for(int front=0;front<N-k;++front){
			int back = front+k;
			for(int i=front+1;i<back;++i){
				dp[front][back] = max(dp[front][back], dp[front][i]+dp[i][back]+ values[front]*values[i]*values[back]);
			}
		}
	}
	return dp[0][N-1];
}

int main(){
	int N;
	cin>>N;
	vector<int> nums(N,0);
	for(int i=0;i<N;++i){
		cin>>nums[i];
	}

	int res = maxCoin(nums);
	cout<<res<<endl;
	return 0;
}
