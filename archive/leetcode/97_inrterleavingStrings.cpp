#include "bits/stdc++.h"
#include <numeric>
#include <string>


int main() {
  std::string s1, s2, s3;
  std::cin >> s1 >> s2 >> s3;

  uint count[26];
  memset(count, 0u, sizeof(uint)*26);


  for (char x : s3) {
    count[x - 'a']++;
  }

  for (char x : s1) {
    count[x - 'a']--;
  }

  for (char x : s2) {
    count[x - 'a']--;
  }

  if (std::accumulate(count, count + 26, 0u) == 0u) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return 0;
}
