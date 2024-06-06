#include <bits/stdc++.h>
#include <regex>

using namespace std;

struct tc {
  int E = INT16_MAX;
  int W = INT16_MAX;
  int A = INT16_MAX;
};

void set_val(struct tc *a, int *b) {
  a->E = *b;
  a->W = *(b + 1);
  a->A = *(b + 2);
}

int main() {
  int N;
  cout << "enter no of city:";
  cin >> N;
  cout << "__________________\n";
  int cost[N][3];

  for (int i = 0; i < N; i++)
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

  struct tc info[N][N];

  for (int i = 0; i < N; i++)
    set_val(info[i] + i, cost[i]);

  for (int i = 1; i < N; i++) {
    // find info[0][i]
    // E
    if (info[i][i].W < info[i][i].A)
      info[0][i].W = info[0][i].W < (info[i][i].W + info[0][i - 1].E)
                         ? info[0][i].W
                         : info[i][i].W + info[0][i - 1].E;
    else
      info[0][i].A = info[0][i].A < (info[i][i].A + info[0][i - 1].E)
                         ? info[0][i].A
                         : info[i][i].A + info[0][i - 1].E;  
    // W
    if (info[i][i].E < info[i][i].A)
      info[0][i].E = info[0][i].E < (info[i][i].E + info[0][i - 1].W)
                         ? info[0][i].E
                         : info[i][i].E + info[0][i - 1].W;
    else
      info[0][i].A = info[0][i].A < (info[i][i].A + info[0][i - 1].W)
                         ? info[0][i].A
                         : info[i][i].A + info[0][i - 1].W;
      // A
    if (info[i][i].E < info[i][i].W)
      info[0][i].E = info[0][i].E < (info[i][i].E + info[0][i - 1].A)
                         ? info[0][i].E
                         : info[i][i].E + info[0][i - 1].A;
    else
      info[0][i].W = info[0][i].W < (info[i][i].W + info[0][i - 1].A)
                         ? info[0][i].W
                         : info[i][i].W + info[0][i - 1].A;
  }

  cout << info[0][N - 1].E << " " << info[0][N - 1].W << " " << info[0][N - 1].A
       << endl;

  return 0;
}
