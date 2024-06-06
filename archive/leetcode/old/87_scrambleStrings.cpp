#include <bits/stdc++.h>
using namespace std;

bool isScramble(string s1, string s2){
	if(s1.size() != s2.size())
		return false;
	if(s1.size()==0)
		return true;
	if(s1==s2)
		return true;
	//check annagram
	string a=s1, b = s2;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a!=b)
		return false;

	int n=s1.size();
	for(int i=1;i<n;++i){
		//0,i i+1, n-1
		if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i, n-i), s2.substr(i,n-i)) )
			return true;

		if( isScramble(s1.substr(0,i), s2.substr(n-i,i)) && isScramble(s1.substr(i, n-i), s2.substr(0,n-i)) )
			return true;

	}
	return false;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;

	if(isScramble(s1, s2))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}
