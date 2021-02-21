#include <bits/stdc++.h>
using namespace std;

int distSubsequence(string s1,string s2){
	int M=s1.size(), N=s2.size();
	int count[M+1][N+1];
	for(int i=0;i<M+1;++i){
		for(int j=0;j<N+1;++j){
			count[i][j]=0;
		}
	}
	for(int i=0;i<M+1;++i){
		count[i][0]=1;
	}
	for(int i=1;i<M+1;++i){
		for(int j=1;j<N+1;++j){
			if(i>=j){
				if(s1[i-1]==s2[j-1]){
					count[i][j]=count[i-1][j-1]+count[i-1][j];
				}
				else {
					count[i][j]=count[i-1][j];
				}
			}
		}
	}
	return count[M][N];
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int res = distSubsequence(s1, s2);
	cout<<res<<endl;
	return 0;
}
