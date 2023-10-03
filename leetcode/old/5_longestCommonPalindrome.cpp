#include <bits/stdc++.h>

using namespace std;

string solve(string s){
	int N=s.size();
	bool dp[N][N];
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j)
			dp[i][j]=false;
	}
	// length 1
	for(int i=0;i<N;++i)
		dp[i][i]=true;
	// length 2
	for(int i=0;i<N-1;++i){
		if(s[i]==s[i+1])
			dp[i][i+1]=true;
	}
	//length 3+
	for(int k=3;k<=N;++k){
		for(int i=0;i<N-k+1;++i){
			int j=i+k-1;
			if(s[i] == s[j] && dp[i+1][j-1]==true)
				dp[i][j]=true;
		}
	}
	int li=0,lj=0;
	for(int i=0;i<N;++i){
		for(int j=i;j<N;++j){
			if(dp[i][j]==true && j-i > lj-li){
				lj=j;li=i;
			}
		}
	}
	return s.substr(li,lj-li+1);
}

int main(){
	string s="juuuj";
	cin>>s;
	string ans = solve(s);
	cout<<ans<<endl;
	return 0;
}
