#include <bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix){
	int M=matrix.size(), N=matrix[0].size();
	vector<vector<int>> dp(M, vector<int>(N,0));
	int maxHeight=0;
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			if(i==0 || j==0 || matrix[i][j]=='0'){
				dp[i][j] = matrix[i][j]-'0';
			}
			else {
				dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]), dp[i-1][j-1])+1;
			}
			maxHeight = max(dp[i][j], maxHeight);
		}
	}
	return maxHeight*maxHeight;
}

int main(){
	int M,N;
	cin>>M>>N;

	vector<vector<char>> matrix(N,vector<char>(M,0));
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j)
			cin>>matrix[i][j];
	}
	int res = maximalSquare(matrix);
	cout<<res<<endl;
	return 0;
}
