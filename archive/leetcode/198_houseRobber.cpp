#include "bits/stdc++.h"
#include <cstring>
#include <sys/types.h>
#include <vector>

using namespace std;


int main () {
  // input
  uint t;
  cin>>t;
  vector<uint> arr;

  while (t--) {
    uint x;
    cin>>x;
    arr.push_back(x);
  }
  // solve.
  uint dp[2][arr.size()];
  memset(dp, 0u, 2*arr.size()*sizeof(uint));

  // init
  dp[0][0] = 0u;
  dp[1][0] = arr[0];
  for(uint idx=1; idx < arr.size(); ++idx) {
    // pick current elem.
    dp[1][idx] = dp[0][idx-1] + arr[idx];
    // skip current elem.
    dp[0][idx] = max(dp[1][idx-1], dp[0][idx-1]);
  }
  cout <<"asdad: " << dp[0][arr.size()-1] <<  dp[1][arr.size()-1] << endl;
  if (dp[0][arr.size()-1] > dp[1][arr.size()-1])
    cout << dp[0][arr.size()-1] << endl;
  else
    cout << dp[1][arr.size()-1] << endl;
  /*
    2  7 9  3   1
  0 0  2 7  11  11
  1 2  7 11 10  12

   2 1 1 2
 0 0 2 2 3
 1 2 1 3 3
   */

  return 0;
}
