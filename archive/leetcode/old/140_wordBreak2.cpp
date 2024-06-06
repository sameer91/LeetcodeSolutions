#include<bits/stdc++.h>
using namespace std;

vector<string> wordBreak(string s, vector<string>& wordDict){
	vector<vector<string>> list(s.size());
	int N=s.size(), M=wordDict.size();

	for(int j=0;j<M;++j){
		if(s.substr(0,wordDict[j].size()) == wordDict[j]){
			list[wordDict[j].size()-1].push_back(wordDict[j]);
		}
	}
	for(int i=1;i<N;++i){
		for(int j=0;j<M;++j){
			if(!list[i-1].empty() && i+wordDict[j].size()<=N && s.substr(i,wordDict[j].size()) == wordDict[j]){
				for(int k=0;k<list[i-1].size();++k){
					list[i+wordDict[j].size()-1].push_back(list[i-1][k]+' '+wordDict[j]);
				}
			}
		}
	}
	return list[N-1];
}

int main(){
	string s;
	cin>>s;
	int N;
	cin>>N;
	vector<string> dict(N);
	for(int i=0;i<N;++i)
		cin >> dict[i];

	vector<string> res = wordBreak(s, dict);

	for(int i=0;i<res.size();++i){
		cout<<res[i]<<endl;
	}

	return 0;
}
