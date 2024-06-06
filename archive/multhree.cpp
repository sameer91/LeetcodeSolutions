#include <iostream>
using namespace std;

long long slimit(long long sum)
{
  long long temp = 0;
  while (sum > 10)
  {
    temp += sum % 10;
    sum /= 10;
  }
  return temp + sum;
}

int main()
{
  int T, d0, d1;
  long long K, sum;

  cin >> T;

  while (T--)
  {
    sum = 0;
    cin >> K >> d0 >> d1;

    sum += d0;
    sum += d1;
    K = K - 2;
    while (K--)
    {
      int temp = 0;

      temp = sum % 10;
      sum += temp;
    }
    while (sum > 10)
      sum = slimit(sum);

    if (sum % 3 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
