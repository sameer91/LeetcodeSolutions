#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector<int> maxNum(vector<int> a, vector<int> b){
	if(a.size()>b.size())
		return a;
	if(a.size()<b.size())
		return b;

	for(int i=0;i<a.size();++i){
		if(a[i]>b[i])
			return a;
		if(a[i]<b[i])
			return b;
	}
	return a;
}

vector<int> getMax(vector<int> &nums1, vector<int> &nums2, int k){
	int m=nums1.size(), n=nums2.size();
	vector<vector<int>>  m1(k+1), m2(k+1);
	vector<int> s1,s2;
	for(int i=0;i<m;++i){
		if(s1.empty()){
			s1.push_back(nums1[i]);
		}
		else {
			while(!s1.empty() && s1.back()<nums1[i] && m-1-i >= k-s1.size() ){
				s1.pop_back();
			}
			if(s1.size() < k)
				s1.push_back(nums1[i]);

		}
	}
	for(int i=s1.size();i>0;--i){
		m1[i]=s1;
		//remove one digit
		int loc =0, flag = 0;
		while(loc<s1.size()-1){
			if(s1[loc] < s1[loc+1]){
				s1.erase(s1.begin()+loc);
				flag=1;
				break;
			}
			loc++;
		}
		if (!flag && loc == s1.size() - 1) {
			s1.pop_back();
		}
	}
	for(int j=0;j<n;++j){
		if(s2.empty()){
			s2.push_back(nums2[j]);
		}
		else {
			while(!s2.empty() && s2.back()<nums2[j] && n-1-j >= k-s2.size() ){
				s2.pop_back();
			}
			if(s2.size()<k)
				s2.push_back(nums2[j]);
		}
	}
	for(int i=s2.size();i>0;--i){
		m2[i]=s2;
		//remove one digit
		int loc=0, flag = 0;
		while(loc<s2.size()-1){
			if(s2[loc] < s2[loc+1]){
				s2.erase(s2.begin()+loc);
				flag=1;
				break;
			}
			loc++;
		}
		if(!flag && loc == s2.size()-1){
			s2.pop_back();
		}
	}
	vector<int> res;
	res = maxNum(m1[k], m2[k]);
	for(int i=1;i<=m;++i){
		// i from nums1 and k-i from nums2
		int j=k-i;
		//m1[i] & m2[j]
		int ires=0,i1=0,i2=0;
		vector<int> temp(k,0);
		while(k == m1[i].size()+ m2[j].size() && ires < k){
			if(i1<m1[i].size() && i2<m2[j].size()){
				if(m1[i][i1]>m2[j][i2]){
					temp[ires++]=m1[i][i1++];
				}
				else if(m1[i][i1] < m2[j][i2]){
					temp[ires++]=m2[j][i2++];
				}
				//equal values
				else {
					//This is still a bit wonky needs some work
					//maybe keep removeing front as we add to temp and then
					//here use m1[i] >/=/< m2[j] to get lexicographical order
					int k=1;
					while(i1+k < m1[i].size() && i2+k < m2[j].size() && nums1[i1+k]==nums2[i2+k]){
						k++;
					}
					if(i2+k == m2[j].size()){
						temp[ires++]=m1[i][i1++];
					}
					else if(i1+k < m1[i].size() && m1[i][i1+k]>m2[j][i2+k]){
						temp[ires++]=m1[i][i1++];
					}
					else {
						temp[ires++]=m2[j][i2++];
					}
				}
			}
			else if(i1<m1[i].size()){
				temp[ires++]=m1[i][i1++];
			}
			else {
				temp[ires++]=m2[j][i2++];
			}

		}
		res = maxNum(res, temp);
	}


	return res;
}

int main(){
	int m,n;
	cin>>m>>n;
	vector<int> nums1(m,0), nums2(n,0);
	for(int i=0;i<m;++i) cin>>nums1[i];
	for(int j=0;j<n;++j) cin>>nums2[j];
	int k;
	cin>>k;
	vector<int> res = getMax(nums1, nums2, k);

	for(int i=0;i<res.size();++i)
		cout<<res[i];
	cout << endl;

	return 0;
}
