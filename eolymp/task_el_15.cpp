#include <algorithm>
#include <cstdio>
#include <execution>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

void pr(pair<int, int> &target, vector<vector<pair<int, int>>> &parents) {

  if (target.first < parents[target.first][target.second].first) {
    if (parents[target.first][target.second].first == -1 &&
        parents[target.first][target.second].second == -1) {
      return;
    }
    pr(parents[target.first][target.second], parents);
    cout << "F";
  } else {

    if (parents[target.first][target.second].first == -1 &&
        parents[target.first][target.second].second == -1) {
      return;
    }
    pr(parents[target.first][target.second], parents);
    cout << "R";
  }
}

void solve() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> field(m, vector<int>(n));
  vector<vector<pair<int, int>>> parents(
      m, vector<pair<int, int>>(n, pair(-1, -1)));
  vector<vector<int>> dp(m, vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> field[i][j];
    }
  }

  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if (i == m - 1 && j == 0)
        continue;

      if (i == m - 1) {
        parents[i][j] = {i, j - 1};
        field[i][j] += field[i][j - 1];
      } else if (j == 0) {
        parents[i][j] = {i + 1, j};
        field[i][j] += field[i + 1][j];
      } else {
        if (field[i][j - 1] >= field[i + 1][j]) {
          parents[i][j] = {i, j - 1};
          field[i][j] += field[i][j - 1];
        } else {
          parents[i][j] = {i + 1, j};
          field[i][j] += field[i + 1][j];
        }
      }
    }
  }

  pair<int, int> target = {0, n - 1};
  pr(target, parents);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();

  return 0;
}
