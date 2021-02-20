#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums){
	//solve in 2 step (0 to n-2) and (1 to n-1)
	int N=nums.size();
	if(N==0)
		return 0;
	if(N==1)
		return nums[0];
	int pre = 0, cur=0;
	for(int i=0;i<=N-2;++i){
		int temp = max(cur,pre+nums[i]);
		pre=cur;
		cur=temp;
	}
	int res = max(pre,cur);
	pre=0;cur=0;
	for(int i=1;i<=N-1;++i){
		int temp = max(cur, pre+nums[i]);
		pre=cur;
		cur=temp;
	}
	return max(res,max(pre,cur));
}

int main(){
	int N;
	cin>>N;

	vector<int> nums(N, 0);
	for(int i=0;i<N;++i)
		cin>>nums[i];

	int res = rob(nums);

	cout<<res<<endl;
	return 0;
}
