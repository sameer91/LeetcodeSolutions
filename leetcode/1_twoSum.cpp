#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
	unordered_map<int, int> hash;
	for(int i=0;i<nums.size();++i)
		hash.insert(make_pair(nums[i], i));
	for(int i=0;i<nums.size();++i){
		int rem = target-nums[i];
		if(nums[i] != rem && hash.find(rem) != hash.end()){
			return vector<int>{hash[nums[i]], hash[rem]};
		}
	}
	return {0,0};
}

int main() {
	int n;
	cin>>n;
	vector<int> nums(n,0);
	for(int i=0;i<n;++i)
		cin>>nums[i];
	int t=0;
	cin>>t;
	vector<int> res = twoSum(nums, t);
	cout<<res[0]<<' '<<res[1]<<endl;
	return 0;
}
