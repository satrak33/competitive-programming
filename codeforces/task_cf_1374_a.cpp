#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int x, y, n;
    cin >> x >> y >> n;

    cout << ((n - y) / x) * x + y << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
