#include <bits/stdc++.h>

using namespace std;

int main() {
  int T = 0, a, b, freq[26];
  cin >> T;


  string strs[T], temp, ans;

  for (int i = 0; i < T; i++)
    cin >> strs[i];
  for (int i = 0; i < T; i++) {
    temp = strs[i];
    a = 0;
    b = (1 + temp.length()) / 2;
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < temp.length()/2; i++)
    {
      freq[ temp[a+i] - 'a']++;
      freq[temp[b+i] - 'a']--;
    }

    bool ans=true;
    for(int i = 0; i<26;i++){
      if(freq[i] != 0) {
        ans = false;
        break;
      }
    }
    if(ans)
      cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
      
    
    
    
    }

  return 0;
}
