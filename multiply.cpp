#include<bits/stdc++.h>
using namespace std;

string multiply(string s1, string s2){
  int l1=s1.size();
  int l2=s2.size();

  vector<int> result (l1+l2, 0);
  for(int i = l1-1; i>=0;i--){
    int n1 = s1[i] -'0' ;
    int carry = 0;
    for (int j = l2 - 1; j >= 0; j--) {
      int n2 = s2[j] -'0';
      result[i+j+1] = result[i+j+1] + n1*n2 + carry;
      carry = result[i+j+1] /10;
      result[i+j+1] = result[i+j+1]%10;
    }
    result[i-1] = carry;
  }
  auto itr = result.begin();
  while(*itr == 0)
    itr++;
  string res = "";
  for(;itr!= result.end(); itr++){
    res.append(to_string(*itr));
  }
  return res;
}


int main () {
  string s1="", s2="";
  string result ="";
  cin >> s1>>s2;

  result =  multiply(s1,s2);
  cout << result<<endl;

}
