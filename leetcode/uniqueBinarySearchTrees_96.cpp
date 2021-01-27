#include <bits/stdc++.h>
using namespace std;

int uniqueBSTs(int N){
	vector<int> count(N+1,0);
	count[0]=1;
	count[1]=1;
	for(int i=2;i<N+1;++i){
		for(int j=1;j<=i;++j){
			count[i]+= count[j-1]*count[i-j];
		}
	}
	return count[N];
}

int main(){
	int n;
	cin>>n;
	int res = uniqueBSTs(n);
	cout<<res<<endl;

	return 0;
}
