#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> cnt(1e6 + 1, 0);
  int mx = 0;

  while (n--) {
    int x;
    cin >> x;

    cnt[x]++;
    mx = max(mx, x);
  }

  for (int d = mx; d > 0; d--) {
    int sm = 0;
    for (int j = d; j <= mx; j += d) {
      sm += cnt[j];
    }

    if (sm >= 2) {
      cout << d << "\n";
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
