#include<bits/stdc++.h>
using namespace std;

int uniquePathOBS(vector<vector<int>>& grid){
	int m=grid.size();
	int n=grid[0].size();
	int count[m][n];
	//base cond
	count[0][0]=1;
	for(int i=1;i<m;++i){
		if(grid[i][0]!=1)
			count[i][0]=count[i-1][0];
		else
			count[i][0]=0;
	}
	for(int i=1;i<n;++i){
		if(grid[0][i]!=1)
			count[0][i]=count[0][i-1];
		else
			count[0][i]=0;
	}

	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			if(grid[i][j]!=1){
				count[i][j]=count[i-1][j]+count[i][j-1];
			}
			else
				count[i][j]=0;
		}
	}

	return count[m-1][n-1];
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<int>> grid(m);
	for(int i=0;i<m;++i){
		grid[i] = vector<int>(n);
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>grid[i][j];
		}
	}
	int res = uniquePathOBS(grid);
	cout<<res<<endl;

	return 0;
}
