#include <bits/stdc++.h>
using namespace std;

template <typename T> T add_this(T &a, T &b) { return a + b; }

int maxProfit(vector<int> &prices) {
  int b1 = INT_MIN, b2 = INT_MIN, s1 = 0, s2 = 0;
  for (int i = 0; i < prices.size(); ++i) {
	int tb1 = b1, tb2 = b2, ts1 = s1, ts2 = s2;
	b1 = max(tb1, -prices[i]);
	s1 = max(s1, tb1 + prices[i]);
	b2 = max(b2, ts1 - prices[i]);
	s2 = max(s2, tb2 + prices[i]);
  }
  return max(s1, s2);
}

int main() {
  int N;
  cin >> N;
  vector<int> prices(N);
  for (int i = 0; i < N; ++i) {
	cin >> prices[i];
  }
  int res = maxProfit(prices);
  cout << res << endl;
  int x = 10, t = 100;
  cout << "Adding 0_0\n" << add_this(x, t) << endl;
  return 0;
}
