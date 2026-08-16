#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  bool is_a = (2 * b - c > 0) && ((2 * b - c) % a == 0);
  bool is_b = ((a + c) % 2 == 0) && (((a + c) / 2) % b == 0);
  bool is_c = (2 * b - a > 0) && ((2 * b - a) % c == 0);

  if (is_a || is_b || is_c) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
