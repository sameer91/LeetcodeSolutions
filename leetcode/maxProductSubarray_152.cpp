#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

int maxProduct(vector<int> nums){
	int N=nums.size(),res=0;
	vector<pair<int,int>> maxVal(N,make_pair(0, 0));
	maxVal[0]=make_pair(nums[0], nums[0]);

	for (int i=1; i<N; ++i) {
		if(nums[i]<=0){
			maxVal[i].first=max(nums[i],maxVal[i-1].second*nums[i]);
			maxVal[i].second=min(maxVal[i-1].first*nums[i],nums[i]);
		}
		else {
			maxVal[i].first=max(nums[i],maxVal[i-1].first*nums[i]);
			maxVal[i].second=min(nums[i],maxVal[i-1].second*nums[i]);
		}
		res=max(res,maxVal[i].first);
	}
	return res;

}

int main() {
	int N;
	cin>>N;
	vector<int> arr(N,0);
	for (int i=0; i<N; ++i) {
		cin>>arr[i];
	}

	int res = maxProduct(arr);
	cout<<res<<endl;
	return 0;
}
