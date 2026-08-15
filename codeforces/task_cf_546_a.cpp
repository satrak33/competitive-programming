#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  ll k, n, w;
  cin >> k >> n >> w;

  cout << max(static_cast<ll>(0), (((2 * k) + ((w - 1) * k)) * w / 2) - n);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
