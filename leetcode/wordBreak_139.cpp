#include<bits/stdc++.h>
using namespace std;

bool Util(string s, vector<string>& dict){
	vector<bool> match(s.size(),false);

	for(int i=0;i<s.size();++i){
		for(int j=0;j<dict.size();++j){
			if((i==0 || match[i-1]) && s.substr(i,dict[j].size()) == dict[j]){
				match[i+dict[j].size()-1]=true;
			}
		}
	}
	return match[s.size()-1];
}

bool wordBreak(string s, vector<string>& wordDict){
	return Util(s, wordDict);
}

int main(){
	string s;
	cin>>s;
	int N;
	cin>>N;
	vector<string> dict(N);
	for(int i=0;i<N;++i)
		cin >> dict[i];

	if(wordBreak(s, dict))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}
