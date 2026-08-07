#include <algorithm>
#include <iostream>

using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long y, x;
    cin >> y >> x;

    long long s = max(y, x);
    long long ans;

    if (s % 2 == 0) {
      if (y == s) {
        ans = s * s - x + 1;
      } else {
        ans = (s - 1) * (s - 1) + y;
      }
    } else {
      if (x == s) {
        ans = s * s - y + 1;
      } else {
        ans = (s - 1) * (s - 1) + x;
      }
    }

    cout << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
