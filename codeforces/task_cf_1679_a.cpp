#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  if (n < 4 || n & 1) {
    cout << -1 << "\n";
  } else if (n % 6 == 0) {
    cout << n / 6 << " " << n / 4 << "\n";
  } else {
    cout << n / 6 + 1 << " " << n / 4 << "\n";
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
