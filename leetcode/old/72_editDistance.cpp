#include <bits/stdc++.h>
using namespace std;

int minDistance(string w1, string w2){
	int n=w1.size(), m=w2.size();
	int dist[n+1][m+1];
	for(int i=0;i<n+1;++i){
		for(int j=0;j<m+1;++j){
			dist[i][j]=0;
		}
	}
	//base cond. w1 empty or w2 empty
	//w1 empty
	for(int i=0;i<m+1;i++){
		dist[0][i]=i;
	}
	//w2 empty
	for(int i=0;i<n+1;++i){
		dist[i][0]=i;
	}

	for(int i=1;i<n+1;++i){
		for(int j=1;j<m+1;++j){
			//match
			if(w1[i-1]==w2[j-1]){
				dist[i][j]=dist[i-1][j-1];
			}
			else {
				//min of all possibilities + 1 operation
				dist[i][j] = min(dist[i-1][j-1], min(dist[i-1][j], dist[i][j-1])) + 1;
			}
		}
	}
	return dist[n][m];
}

int main(){
	string s1,s2;

	cin>>s1>>s2;

	int res = minDistance(s1, s2);

	cout<<res<<endl;
	return 0;
}
