#include <iostream>

using namespace std;
using ll = long long;

const ll MODULO = 1e9 + 7;

ll binpow(ll a, ll b, ll m) {
  if (b == 0) {
    return 1;
  }

  ll res = binpow(a, b / 2, m);

  if (b % 2 == 0) {
    return res * res % m;
  } else {
    return a * res % m * res % m;
  }
}

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;

  cout << binpow(a, binpow(b, c, MODULO - 1), MODULO) << "\n";
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
