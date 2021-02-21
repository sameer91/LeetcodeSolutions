#include <bits/stdc++.h>
using namespace std;

int LongestValidParentheses(string s){
	//use stacks
	stack<int> stk;
	stk.push(-1);
	int len=0;
	int i=0;
	while(i<s.size()){
		if(s[i]=='(')
			stk.push(i);
		else {
			if(!stk.empty()){
				stk.pop();
			}
			if(!stk.empty()){
				if(len < i-stk.top())
					len=i-stk.top();
			}
			else {
				stk.push(i);
			}
		}
		i++;
	}
	return len;
}

int main(){
	string s;
	cin>>s;

	int len = LongestValidParentheses(s);

	cout<<len<<endl;
	return 0;
}
