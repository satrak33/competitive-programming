#include <iostream>

using namespace std;
using ll = long long;

ll binpow(ll x, ll n, ll m) {
  if (n == 0) {
    return 1;
  }

  ll ans = binpow(x, n / 2, m);
  if (n % 2 == 0) {
    return ans * ans % m;
  } else {
    return x * ans % m * ans % m;
  }
}
void solve() {
  ll n;
  cin >> n;

  cout << binpow(2, n, 1e9 + 7);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
