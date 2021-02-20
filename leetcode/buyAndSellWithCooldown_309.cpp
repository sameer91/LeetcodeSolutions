#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices){
	int N=prices.size();
	if(N==0 || N==1)
		return 0;
	vector<int> buy(N,INT_MIN),sell(N,0),hold(N,0);
	//day 0
	buy[0]=-prices[0];
	//day 1
	buy[1]=max(buy[0],-prices[1]);
	sell[1]=max(0,prices[1]+buy[0]);
	for(int i=2;i<N;++i){
		buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
		sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
	}
	return max(0,sell[N-1]);
}

int main(){
	int N;
	cin>>N;
	vector<int> prices(N,0);

	for(int i=0;i<N;++i){
		cin>>prices[i];
	}
	int res = maxProfit(prices);
	cout<<res<<endl;
	return 0;
}
