#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if (mask & 1 << i) {
        // present
      }
    }
  }

  for (int i = m;; i = (i - 1) & m) {
    // current

    if (i == 0)
      break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
