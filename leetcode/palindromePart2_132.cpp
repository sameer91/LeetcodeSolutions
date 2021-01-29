#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int minCut(string s){
		int N=s.size();
		bool isP[N][N];
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				isP[i][j]=false;
			}
		}
		int minCuts[N+1];
		for(int i=0;i<N+1;++i) minCuts[i]=i-1;

		for(int j=0;j<N;++j){
			for(int i=j;i>=0;--i){
				if(s[i]==s[j] && (j-i<2 || isP[i+1][j-1])){
					isP[i][j]=true;
					minCuts[j+1]=min(minCuts[j+1],1+minCuts[i]);
				}
			}
		}

		return minCuts[N];
	}

};

int main(){
	string s;
	cin>>s;

	Solution x;
	int res = x.minCut(s);
	cout<<res<<endl;

	return 0;
}
