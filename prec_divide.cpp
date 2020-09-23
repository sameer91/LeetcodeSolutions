#include <bits/stdc++.h>
using namespace std;

string divide(int a, int b, int n) {
  if (b == 0) {
    return "Inf";
  }
  if (a == 0) {
    return "0."+string(n,'0');
  }
  string result = "";

  if (a < 0 && b > 0 || b < 0 && a > 0) {
    cout << "-";
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : n;
  }
  int  d = a/b, i =0;
  for(i = 0; i<=n;i++){
    result.append(to_string(d));
    a = a -(d*b);
    if(a == 0)
      break;
    a = a*10;
    d = a/b;
    if(i == 0)
      result.push_back('.');
  }
  if(i == 0)
    result.push_back('.');
  while(i < n){
    result.push_back('0');
    i++;
  }

  return result;
}

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  string res;
  res = divide(a, b, n);

  cout << res << endl;
  return 0;
}
