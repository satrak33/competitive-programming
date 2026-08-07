#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int k;
  cin >> k;

  for (ll i = 1; i <= k; ++i) {
    cout << i * i * (i * i - 1) / 2 - 4 * (i - 2) * (i - 1) << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
