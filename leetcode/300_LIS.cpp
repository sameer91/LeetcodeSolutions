#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &nums){
	int n=nums.size(), res=1;
	vector<int> lis(n,1);

	for(int i=1;i<n;++i){
		for(int j=0;j<i;++j){
			if(nums[i]>nums[j]){
				lis[i]=max(lis[i],lis[j]+1);
			}
		}
		res = max(res,lis[i]);
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	vector<int> nums(n,0);

	for(int i=0;i<n;++i)
		cin>>nums[i];

	int res = LIS(nums);
	cout<<res<<endl;
	return 0;
}
