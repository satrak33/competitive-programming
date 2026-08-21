#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

void solve() {
  int n;
  cin >> n;

  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    if (x != i) {
      int diff = abs(i - x);
      ans = gcd(ans, diff);
    }
  }

  cout << ans << "\n";
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
