#include<bits/stdc++.h>
using namespace std;

int main() {
	int num;
	int k;
	cin>>num>>k;
	string digits = to_string(num);
	int tLoc;
	k=k%digits.size();
	string ans=digits;
	for (int i=0; i < digits.size(); ++i) {
		tLoc=i-k;
		if(tLoc<0)
			tLoc+=digits.size();
		ans[tLoc]=digits[i];
	}

	cout<<ans<<endl;
	return 0;

}
