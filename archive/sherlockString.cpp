#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
  int rem = 1;
  int freq[26]={0};
  for(int i = 0; i<s.size(); i++){
    freq[s[i] - 'a']++;
  }
  int base = -1;

  for(int i =0; i< 26;i++){
    if(freq[i] == 0)
    continue;
    else {
      if(freq[i] == base)
        continue;
      else {
        if(base == -1){
          base = freq[i];
          continue;
        }
        if(rem == 1 && (freq[i] == base + 1 || freq[i] == 1)){
          rem = 0;
          continue;
        }
        return "NO";
      }
    }
  }
  return "YES";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = isValid(s);

  fout << result << "\n";

  fout.close();

  return 0;
}
