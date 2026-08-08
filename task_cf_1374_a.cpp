#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int x, y, n;
    cin >> x >> y >> n;

    if (n % x == y) {
      cout << n << "\n";
    } else if (y < n % x) {
      cout << n - (n % x - y) << "\n";
    } else {
      cout << n - n % x - x + y << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
