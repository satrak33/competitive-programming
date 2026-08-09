#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 3 == 0 && b >= a / 2 && a >= b / 2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
