#include<bits/stdc++.h>
using namespace std;

bool findSpecial(string substr){
  int i = 0, j = substr.size()-1;
  char ch = substr[0];
  while(i < j){
    if(substr[i] != ch || substr[j] != ch)
      return false;
    i++;
    j--;
  }
  return true;
}


int substrCount(string s){
  char ch;
  int count = 0;
  string uniq="";
  vector<int> freq;
  for (int i = 0; i < s.size();) {
     ch = s[i];
     count = 1;
     i++;
     while(s[i] == ch){
       i++;
       count++;
     }
     uniq.push_back(ch);
     freq.push_back(count);
  }
  cout<<uniq<<endl;
  for(int i = 0; i<freq.size();i++)
    cout<<freq[i]<<' ';
  cout<<endl;
  int c1=0,c2=0;
  for(int i = 0; i<uniq.size(); i++){
    if(freq[i] == 1){
      c2++;
      //diffrent in middle
      if(i-1 >= 0 && i+1 < uniq.size()){
        if(uniq[i-1] == uniq[i+1]){
          c2+= min(freq[i-1], freq[i+1]);
        }
      }
    }
    else
    //all element same
    c1+=freq[i] * (freq[i]+1) /2;
  }
  return c1+c2;
}

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;
  //call fun
  cout<<substrCount(s)<<endl;


  return 0;
}
