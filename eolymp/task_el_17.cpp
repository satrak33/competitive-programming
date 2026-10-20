#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  cout << 3LL * binpow(2, n - 1) << "\n";
}
