#include<bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin>>q;
  while(q--){
	string str;
	cin>>str;
	stack<char> stk;
	bool accept=true;
	for (int i = 0; i < str.size(); i++) {
	  if (stk.empty() && (str[i] == ')' || str[i] == ']' || str[i] == '}')) {
		accept=false;
		break;
	  }
	  if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
		stk.push(str[i]);
	  }
	  else {
		if ((stk.top() == '(' && str[i] == ')') ||
			(stk.top() == '[' && str[i] == ']') ||
			(stk.top() == '{' && str[i] == '}'))
		  stk.pop();
		else {
		  accept=false;
		  break;
		}
	  }
	}
	if(stk.empty() && accept)
	  cout<<"YES"<<endl;
	else
	  cout<<"NO"<<endl;
  }
  return 0;
}
