#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> height){
	//Solve stack
	stack<int> stk;
	int res=0;
	for(int i=0;i<height.size();++i){
		if(stk.empty()){
			stk.push(i);
		}
		else {
			if(height[stk.top()] > height[i]){
				stk.push(i);
			}
			else {
				while(!stk.empty() && height[stk.top()] < height[i]){
					int ch=stk.top();
					stk.pop();
					if(stk.empty())
						break;
					int d = i-stk.top()-1;
					res += d * (min(height[i],height[stk.top()])-height[ch]);
				}
				stk.push(i);

			}
		}
	}
	return res;
}

int main(){
	int N;
	cin>>N;
	vector<int> height(N);
	for(int i=0;i<N;++i){
		cin>>height[i];
	}
	int ans=trap(height);

	cout << ans<<endl;
	return 0;
}
