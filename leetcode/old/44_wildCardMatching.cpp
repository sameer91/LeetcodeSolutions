#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p){
	//reges match
	int N=s.size(), M=p.size();
	bool lookup[N+1][M+1];
	memset(lookup,0,sizeof(lookup));

	lookup[0][0]=true;
	for (int i=1; i < M+1; ++i) {
		if(p[i-1]=='*')
			lookup[0][i]=lookup[0][i-1];
	}
	for(int i=1;i<N+1;++i){
		for(int j=1;j<M+1;++j){
			if(lookup[i-1][j-1] && (p[j-1]=='?' || p[j-1]==s[i-1])){
				lookup[i][j]=true;
			}
			else if(p[j-1]=='*'){
				lookup[i][j]= lookup[i][j-1] || lookup[i-1][j];
			}
		}
	}

	return lookup[N][M];
}

int main(){
	string s,p;
	cin>>s>>p;
	bool ans =	isMatch(s, p);
	if(ans)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}
