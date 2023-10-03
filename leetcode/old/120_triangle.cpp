#include<bits/stdc++.h>
using namespace std;

int minTotal(vector<vector<int>>& triangle){
	vector<vector<int>> minPath=triangle;
	for(int i=1;i<minPath.size();++i){
		for(int j=0;j<i+1;++j){
			if(j==0){
				minPath[i][j]+=minPath[i-1][j];
			}
			else if(j==i){
				minPath[i][j]+=minPath[i-1][j-1];
			}
			else {
				minPath[i][j]+=min(minPath[i-1][j],minPath[i-1][j-1]);
			}
		}
	}
	int smallest=INT_MAX,h=minPath.size();
	for(int i=0;i<h;++i){
		if(minPath[h-1][i]<smallest)
			smallest=minPath[h-1][i];
	}
	return smallest;
}

int main(){
	int h;
	cin>>h;
	vector<vector<int>> triangle(h);
	for(int i=0;i<h;i++){
		triangle[i]=vector<int>(i+1);
	}
	for(int i=0;i<h;++i){
		for(int j=0;j<i+1;++j){
			cin>>triangle[i][j];
		}
	}
	int min=minTotal(triangle);
	cout<<min<<endl;
	return 0;
}
