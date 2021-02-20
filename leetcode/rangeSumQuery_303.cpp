#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
	vector<int> arr;
public:
	NumArray(vector<int>& nums){
		arr=nums;
	}
	int sumRange(int i,int j){
		int sum=0;
		for(int k=i;k<=j;++k){
			sum+=arr[k];
		}
		return sum;
	}
};

int main(){
	int n;
	cin>>n;
	vector<int> nums(n,0);
	for(int i=0;i<n;++i)
		cin>>nums[i];
	NumArray *x = new NumArray(nums);
	x->sumRange(0, 1);
	return 0;
}
