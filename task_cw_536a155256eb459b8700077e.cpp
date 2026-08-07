#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<int>> create_spiral(int n) {
  if (n < 1) {
    vector<vector<int>> res;
    return res;
  }

  vector<pair<int, int>> mv = {

      {0, 1},
      {1, 0},
      {0, -1},
      {-1, 0},
  };

  vector<vector<int>> res(n, vector<int>(n, 0));
  int a = 0, b = 0, c = 0;

  for (int i = 1; i <= n * n; ++i) {
    res[a][b] = i;

    if (a + mv[c].first >= n || a + mv[c].first < 0 || b + mv[c].second >= n ||
        b + mv[c].second < 0 || res[a + mv[c].first][b + mv[c].second]) {

      ++c %= 4;
    }
    a += mv[c].first;
    b += mv[c].second;
  }

  return res;
}
// void solve() { vector<vector<int>> res = create_spiral(0); }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   solve();
//   return 0;
// }
