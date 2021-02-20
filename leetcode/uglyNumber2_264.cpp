#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n){
	vector<int> arr(n,0);
	int i2=0,i3=0,i5=0;
	arr[0]=1;
	for(int i=1;i<n;++i){
		int next = min(min(arr[i2]*2,arr[i3]*3), arr[i5]*5);
		arr[i]=next;
		if(next%2==0) i2++;
		if(next%3==0) i3++;
		if(next%5==0) i5++;
	}
	return arr[n-1];
}

int main(){
	int N;
	cin>>N;

	int res = nthUglyNumber(N);
	cout<<res<<endl;
	return 0;
}
