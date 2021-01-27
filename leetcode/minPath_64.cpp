#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid){
	int m=grid.size();
	int n=grid[0].size();
	int sum[m][n];
	sum[0][0]=grid[0][0];
	//1st row and column base cond
	for(int i=1;i<n;++i){
		sum[0][i]=sum[0][i-1]+grid[0][i];
	}
	for(int j=1;j<m;++j){
		sum[j][0]=sum[j-1][0]+grid[j][0];
	}

	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			sum[i][j]=grid[i][j]+min(sum[i-1][j],sum[i][j-1]);
		}
	}

	return sum[m-1][n-1];
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(m);
	for (int i=0; i<m; ++i) {
		grid[i]=vector<int>(n);
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>grid[i][j];
		}
	}
	int res = minPathSum(grid);
	cout<<res<<endl;

	return 0;
}
