#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices){
	int prof=-1,currMax=0;
	int N=prices.size();
	currMax=prices[N-1];
	for(int i=N-1;i>=0;--i){
		if(currMax-prices[i]>prof){
			prof=currMax-prices[i];
		}
		if(prices[i]>currMax){
			currMax=prices[i];
		}
	}
	return prof;
}

int main(){
	int N;
	cin>>N;
	vector<int> arr(N,0);
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	int res = maxProfit(arr);
	cout<<res<<endl;

	return 0;
}
