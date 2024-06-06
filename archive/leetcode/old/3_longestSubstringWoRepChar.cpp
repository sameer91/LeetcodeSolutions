#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstr(string s){
	vector<int> hash(256, -1);
	int maxlen=0, start=-1;
	for(int i=0;i<s.size();++i){
		if(hash[s[i]]>start)
			start = hash[s[i]];
		hash[s[i]]=i;
		maxlen = max(maxlen, i-start);
	}
	return maxlen;
}

int main(){
	string s;
	cin>>s;
	int res =longestUniqueSubstr(s);
	cout<<res<<endl;
	return 0;
}
