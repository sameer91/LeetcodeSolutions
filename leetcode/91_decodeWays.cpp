#include<bits/stdc++.h>
using namespace std;

int numDecoding(string s){
	int N=s.size();
	if(N==0||s[0]=='0')
		return 0;
	//count of string of length n
	vector<int> count(N+1, 0);
	count[0]=1;
	count[1]=1;

	for(int i=2;i<N+1;++i){
		if(s[i-1]=='0' && (s[i-2]=='1'||s[i-2]=='2')){
			count[i]=count[i-2];
		}
		else {
			if(s[i-2]=='1' || (s[i-2]=='2'&& s[i-1]<='6')){
				count[i]=count[i-1]+count[i-2];
			}
			else {
				if(s[i-1] == '0' && (s[i-2]=='0' || s[i-2]>'2'))
					return 0;

				count[i]=count[i-1];
			}
		}
	}
	return count[N];
}

int main(){
	string s;
	cin>>s;

	int count=numDecoding(s);

	cout<<count<<endl;
}
