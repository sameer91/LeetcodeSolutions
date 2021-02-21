#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix){
	int maxArea=0, r=matrix.size(), c=matrix[0].size();
	int h[r][c];

	for(int i=0;i<r;++i){
		stack<int> stk;
		int tempMax=0,j;
		for(j=0;j<c;++j){
			if(matrix[i][j]=='1'){
				if(i==0){
					h[i][j]=1;
				}
				else
					h[i][j]=1+h[i-1][j];
			}
			else
				h[i][j]=0;
			//max hist area
			if(stk.empty() || h[i][stk.top()]<=h[i][j]){
				stk.push(j);
			}
			else {
				while(!stk.empty() && h[i][stk.top()]>h[i][j]){
					int t=stk.top();
					stk.pop();
					if(stk.empty()){
						tempMax = max(tempMax, h[i][t]*(j));
						break;
					}
					tempMax = max(tempMax, h[i][t]*(j-stk.top()-1));
				}
				stk.push(j);
			}
		}
		while(!stk.empty()){
			int t=stk.top();
			stk.pop();
			if(stk.empty()){
				tempMax=max(tempMax, h[i][t]*c);
				break;
			}
			tempMax = max(tempMax, h[i][t]*(c-stk.top()-1));
		}

		maxArea = max(maxArea, tempMax);
	}


	return maxArea;
}

int main(){
	int r,c;
	cin>>r>>c;
	vector<vector<char>> matrix(r);
	for(int i=0;i<r;++i){
		matrix[i]=vector<char>(c);
	}

	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			cin>>matrix[i][j];
		}
	}

	int res = maximalRectangle(matrix);
	cout<<res<<endl;
	return 0;
}
