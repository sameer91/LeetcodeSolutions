#include<bits/stdc++.h>
using namespace std;


bool checkCap(string a,int i){
  while(i>=0){
    if(isupper(a[i]))
      return false;
    i--;
   }
  return true;
}


bool findSeq(string a,string b,int i,int j){
  //closing condition
  if(i<0)
    return false;
  if(j==0){
    if(isupper(a[i])){
      if(a[i] != b[j])
        return false;
      else
        return true;
    }
    else{
      if (toupper(a[i]) == b[j]){
        return checkCap(a, i)||findSeq(a, b, i-1, j);
      }
      else{
        return findSeq(a, b, i-1, j);
      }
    }
  }

  if(isupper(a[i])){
    if(a[i] != b[j])
      return false;
    else
      return findSeq(a, b, i-1, j-1);
  }
  else{
    if (toupper(a[i]) == b[j]){
      return findSeq(a, b, i-1, j-1)||findSeq(a, b, i-1, j);
    }
    else{
      return findSeq(a, b, i-1, j);
    }
  }
}


int main(){
  int q;
  cin>>q;
  while(q--){
    string a,b;
    cin>>a;
    cin>>b;
    if(findSeq(a, b, a.size()-1, b.size()-1))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
