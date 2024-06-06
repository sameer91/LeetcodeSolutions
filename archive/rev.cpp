#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  long long x[T], rev;
  for (int i = 0; i < T; i++)
    cin >> x[i];

  for (int i = 0; i < T; i++) {
    long long temp = x[i];
    rev = 0;
    while (temp > 0) {
      rev = rev * 10 + (temp % 10);
      temp = temp / 10;
    }

    cout << rev << endl;
  }

  return 0;
}
