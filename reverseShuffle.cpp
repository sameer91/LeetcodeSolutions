#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;

  int avail[26]={};
  int require[26] = {};
  string half="";

  for(int i = 0; i<s.size();i++){
    avail[s[i] -'a']++;
  }

  for(int i = 0;i<26;i++){
    require[i] = avail[i] /2;
  }
  int used[26] = {};
  stack<int> ans;
  for(int i = s.size()-1;i>=0; i--){
    int ch = s[i] -'a';
    if(ans.empty()){
      ans.push(ch);
      used[ch]++;
      avail[ch]--;
    }
    else if (require[ch] == used[ch] ){
      avail[ch]--;
    }
    else {
      while(!ans.empty()){
        if((ans.top() > ch) && avail[ans.top()] > require[ans.top()] - used[ans.top()]){
          used[ans.top()]--;
          ans.pop();
        }
        else
          break;
      }
      ans.push(ch);
      used[ch]++;
      avail[ch]--;
      int eval=1;
      for(int i = 0;i<26;i++)
        if(used[i] != require[i])
          eval=0;

      if(eval)
        break;
    }
  }
  string op="";
  while(!ans.empty()){
    op.push_back(ans.top()+'a');
    ans.pop();
  }
  reverse(op.begin(),op.end());
  cout << op <<endl;
  return 0;
}
