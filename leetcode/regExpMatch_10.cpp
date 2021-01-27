#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p){
	int N=s.size(),M=p.size();
	bool dp[N+1][M+1];

	memset(dp, 0, sizeof(dp));
	dp[0][0]=true;

	for(int i=1;i<=M;++i){
		if(p[i-1]=='*'){
			dp[0][i]=dp[0][i-2];
		}
	}

	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			if(p[j-1] == '*'){
				//p[j-2]
				bool temp=false;
				if(s[i-1]==p[j-2] || p[j-2]=='.')
					temp =true;
				dp[i][j]=(dp[i-1][j]&&temp) || dp[i][j-2];
			}
			else if(p[j-1] == '.' || s[i-1]==p[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}
			else
				dp[i][j]=false;
		}
	}


	return dp[N][M];
}

int main() {
	string s,p;
	cin>>s>>p;
	bool res = isMatch(s, p);
	if(res)
		cout<<true<<endl;
	else
		cout<<false<<endl;
}
