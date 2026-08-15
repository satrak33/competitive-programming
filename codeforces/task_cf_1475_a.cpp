#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    ll n;
    cin >> n;

    if (n & (n - 1)) {
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
