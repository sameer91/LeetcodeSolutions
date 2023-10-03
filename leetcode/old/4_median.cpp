#include <bits/stdc++.h>
using namespace std;

double getMedian(vector<int>& nums1, vector<int>& nums2){
	int n=nums1.size(), m=nums2.size();
	vector<int> a=nums1,b=nums2;
	if(n > m){
		a = nums2; b=nums1;
		n = a.size(); m = b.size();
	}
	int l=0, r = n, mid_len = (n+m+1)/2, a_len, b_len;;
	double l_mid, r_mid;
	while(l<=r){
		a_len = (l+r)/2;
		b_len = mid_len - a_len;

		if(a_len < n && b[b_len-1]>a[a_len]){
			l = a_len+1;
		}
		else if(a_len > 0 && a[a_len-1]>b[b_len]){
			r = a_len - 1;
		}
		else {

			if(a_len==0){
				l_mid = b[b_len-1];
			}
			else if(b_len == 0){
				l_mid = a[a_len-1];
			}
			else {
				l_mid = max(a[a_len-1], b[b_len-1]);
			}
			break;
		}
	}
	if((n+m)%2==1){
		return l_mid;
	}
	if(a_len==n){
		r_mid = b[b_len];
	}
	else if(b_len == m){
		r_mid = a[a_len];
	}
	else {
		r_mid = min(a[a_len], b[b_len]);
	}
	return (l_mid+r_mid)/2;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> nums1(n,0), nums2(m,0);
	for(int i=0;i<n;++i) cin>>nums1[i];
	for(int i=0;i<m;++i) cin>>nums2[i];

	double res = getMedian(nums1,nums2);
	cout<<res<<endl;
	return 0;
}
