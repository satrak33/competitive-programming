#include <iostream>

using namespace std;
using ll = long long;

ll binpow(ll a, ll b, ll m) {
  ll res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll w, h;
  cin >> w >> h;

  cout << binpow(2, w + h, 998244353);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
