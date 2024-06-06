#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows){
	vector<string> z(numRows);
	int i=0,j=0;
	bool flag=false;
	while(j<s.size()){
		if(flag){
			z[i].push_back(s[j]);
			if(i==0){
				flag = false;
				i++;
				j++;
			}
			else {
				i--;
				j++;
			}
		}
		else {
			z[i].push_back(s[j]);
			if(i==numRows-1){
				flag = true;
				i--;
				j++;
			}
			else {
				i++;
				j++;
			}
		}
	}
	string res;
	for(i=0;i<z.size();++i){
		res.append(z[i]);
	}
	return res;
}

int main(){
	string s;
	cin>>s;
	int numRows;
	cin>>numRows;
	string res =convert(s,numRows);
	cout<<res<<endl;
	return 0;
}
