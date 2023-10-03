#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int i, int j){
	while(i<=j){
		if(s[i]!=s[j])
			return false;
		i++;j--;
	}
	return true;
}

void partUtil(string s, int i, vector<string>& path, vector<vector<string>>& res){
	if(i>=s.size()){
		res.push_back(path);
		return;
	}
	for(int k=i;k<s.size();++k){
		if(isPalindrome(s,i,k)){
			path.push_back(s.substr(i,k-i+1));
			partUtil(s, k+1, path, res);
			path.pop_back();
		}
	}
}

vector<vector<string>> partition(string s){
	vector<vector<string>> res;

	if(s.empty()) return res;

	vector<string> path;
	partUtil(s,0,path,res);
	return res;
}

int main(){
	string s;
	cin>>s;

	vector<vector<string>> res=partition(s);

	for(int i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
