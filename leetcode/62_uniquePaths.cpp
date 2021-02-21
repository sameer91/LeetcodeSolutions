#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n){
	int mat[m+1][n+1];
	for(int i=0;i<m+1;++i){
		mat[i][0]=0;
	}
	for(int i=0;i<n+1;++i){
		mat[0][i]=0;
	}
	mat[0][1]=1;
	for(int i=1;i<m+1;++i){
		for (int j=1; j<n+1; ++j) {
			mat[i][j]=mat[i-1][j]+mat[i][j-1];
		}
	}
	return mat[m][n];
}

int main(){
	int m, n;
	cin>>m>>n;
	int res = uniquePaths(m, n);
	cout<<res<<endl;

	return 0;
}
