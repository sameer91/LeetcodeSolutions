#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string s1, string s2, string s3){
	string a=s1+s2, b=s3;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a!=b)
		return false;

	int N=s1.size(), M=s2.size();
	bool dp[N+1][M+1];
	for(int i=0;i<N+1;++i){
		for(int j=0;j<M+1;++j)
			dp[i][j]=false;
	}
	for(int i=0;i<N+1;++i){
		for(int j=0;j<M+1;++j){
			if(i==0 || j==0 ){
				if(i==0 && j==0)
					dp[i][j]=true;
				else if(i==0 && s2[j-1] == s3[j-1])
					dp[0][j]=dp[0][j-1];
				else if(j==0 && s1[i-1] == s3[i-1])
					dp[i][0] = dp[i-1][0];}
			else {
				if(s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]){
					dp[i][j]=dp[i-1][j] || dp[i][j-1];
				}
				else {
					if(s1[i-1]==s3[i+j-1]){
						dp[i][j]=dp[i-1][j];
					}
					if(s2[j-1]==s3[i+j-1]){
						dp[i][j]=dp[i][j-1];
					}
				}
			}
		}
	}
	return dp[N][M];
}

int main(){
	string s1,s2,s3;
	cin>>s1>>s2>>s3;

	bool res = isInterleave(s1, s2, s3);

	if(res)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}
