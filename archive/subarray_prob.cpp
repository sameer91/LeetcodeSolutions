#include <iomanip>
#include <iostream>

using namespace std;

int sum_from_a2b(int *A, int a, int b) {
  int sum = 0;
  for (int i = 0; i <= b; i++) {
    sum += A[a + i];
  }

  return sum;
}

int main() {
  int N, S, count = 0;

  cin >> N >> S;

  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; i + j < N; j++) {
      if (sum_from_a2b(A, i, j) <= S)
        count++;
      else
        break;
    }
  }
  int total;
  double prob = 0;

  total = N * (N + 1) / 2;

  prob = (double)count / total;

  cout << count << ' ';
  cout << total << endl;
  cout << setprecision(8) << prob;
}
