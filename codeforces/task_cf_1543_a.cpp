#include <cstdlib>
#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  ll a, b;
  cin >> a >> b;

  if (a == b) {
    cout << "0 0" << "\n";
    return;
  }

  ll g = abs(a - b);
  ll s = min(a % g, g - (a % g));

  cout << g << ' ' << s << "\n";
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
