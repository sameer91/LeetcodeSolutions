#include <bits/stdc++.h>
#include <vector>
using namespace std;

int numSquares(int n){
	vector<int> minSq(n+1,INT_MAX);
	minSq[0]=0;
	minSq[1]=1;

	for(int i=2;i<n+1;++i){
		for(int j=1; j*j<=i; ++j){
			minSq[i] = min(minSq[i],minSq[i-j*j]+1);
		}
	}
	return minSq[n];
}

int main(){
	int n;
	cin>>n;

	int res = numSquares(n);
	cout<<res<<endl;
	return 0;
}
