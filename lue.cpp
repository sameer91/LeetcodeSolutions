#include <iostream>

using namespace std;

int main() {
  long long x;

  while (1) {
    cin >> x;
    if (x == 42)
      break;
    else
      cout << x << endl;
  }

  return 0;
}
