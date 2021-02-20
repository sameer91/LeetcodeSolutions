#include <bits/stdc++.h>
using namespace std;

int calculateMinHP(vector<vector<int>> dungeon){
	int N=dungeon.size(), M=dungeon[0].size();
	vector<vector<int>> minCount(N+1, vector<int>(M+1,INT_MAX));
	minCount[N-1][M]=1;
	minCount[N][M-1]=1;
	for(int i=N-1;i>=0;--i){
		for(int j=M-1;j>=0;--j){
			minCount[i][j]=min(minCount[i+1][j], minCount[i][j+1])-dungeon[i][j];
			if(minCount[i][j]<=0)
				minCount[i][j]=1;
		}
	}
	return minCount[0][0];
}

int main(){
	int M,N;
	cin>>M>>N;

	vector<vector<int>> dungeon(N);
	for(int i=0;i<N;++i){
		dungeon[i]=vector<int>(M);
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>dungeon[i][j];
		}
	}
	int res = calculateMinHP(dungeon);

	cout<<res<<endl;
	return 0;
}
