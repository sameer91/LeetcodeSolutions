#include <bits/stdc++.h>
using namespace std;

int match(vector<int> **hash_arr, string &temp) {
  int k = temp.size();
  int i = 1, j = k;
  vector<int> prev = *(hash_arr[temp[0] - 'a']);
  while (i < k) {
    vector<int> curr = *hash_arr[temp[i] - 'a'];

    vector<int> hold;
    for (int l = 0; l < prev.size(); l++) {
      if (binary_search(curr.begin(), curr.end(), prev[l] + 1))
        hold.push_back(prev[l] + 1);
    }
    prev = hold;
    i++;
  }
  if (prev.empty())
    return -1;
  else
    return prev[0];
}

int main() {
  string str;
  cin >> str;

  vector<int> *hash_arr[26];

  for (int i = 0; i < 26; i++) {
    hash_arr[i] = new vector<int>;
  }
  for (auto i = 0; i < str.size(); i++) {
    hash_arr[str[i] - 'a']->push_back(i);
  }
  // brute force
  //  int s = 0, e = 1;
  //  for(s = 0; s<str.size();s++) {
  //    for (e = s + 1; e < str.size(); e++) {
  //      // call for reversed s to e
  //      string temp = string(str.begin() + s, str.begin() + 1 + e);
  //      reverse(temp.begin(), temp.end());
  //
  //      if (match(hash_arr, temp) > 0)
  //        cout << temp << endl;
  //    }
  //  }
  // optimised
  set<int> pos;
  int stride = 2;
  for (int i = 0; i <= str.size() - stride; i++) {
    string temp = string(str.begin() + i, str.begin() + i + stride);
    reverse(temp.begin(), temp.end());
    if (match(hash_arr, temp) > 0) {
      reverse(temp.begin(), temp.end());
      cout << temp << endl;
      pos.insert(i);
    }
  }
  stride++;

  for (; stride < str.size(); stride++) {
    set<int> newpos;
    for (auto itr = pos.begin(); itr != pos.end(); itr++) {
      int i = *itr;
      if (i - 1 > 0 && i - 1 + stride <= str.size()) {
        string temp = string(str.begin() + i - 1, str.begin() + i - 1 + stride);
        reverse(temp.begin(), temp.end());
        if (match(hash_arr, temp) > 0 && newpos.find(i-1) == newpos.end()) {
          reverse(temp.begin(), temp.end());
          cout << temp << endl;
          newpos.insert(i-1);
        }
      }
      if (i + stride <= str.size()) {
        string temp = string(str.begin() + i, str.begin() + i + stride);
        reverse(temp.begin(), temp.end());
        if (match(hash_arr, temp) > 0 && newpos.find(i) == newpos.end()) {
          reverse(temp.begin(), temp.end());
          cout << temp << endl;
          newpos.insert(i);
        }
      }
    }
    pos = newpos;
  }

  return 0;
}
