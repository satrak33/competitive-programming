#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<vector<int>> frec(26, vector<int>(26, 0));

  for (int i = 1; i < n; ++i) {
    int a = s[i - 1] - 'A';
    int b = s[i] - 'A';

    frec[a][b]++;
  }

  int mx = 0;
  pair<int, int> cm = {-1, -1};

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (frec[i][j] > mx) {
        mx = frec[i][j];
        cm = {i, j};
      }
    }
  }

  cout << static_cast<char>(cm.first + 'A')
       << static_cast<char>(cm.second + 'A') << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
