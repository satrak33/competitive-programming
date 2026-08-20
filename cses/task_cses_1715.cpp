#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MODULO = (int)1e9 + 7;
const int NMAX = (int)1e6;

int binpow(ll a, ll b) {
  a %= MODULO;
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = 1LL * res * a % MODULO;
    }
    a = 1LL * a * a % MODULO;
    b >>= 1;
  }
  return res;
}

vector<int> fact = []() {
  vector<int> f(NMAX + 1);
  f[0] = 1;

  for (int i = 1; i < f.size(); ++i) {
    f[i] = 1LL * f[i - 1] * i % MODULO;
  }
  return f;
}();

vector<int> ifact = []() {
  vector<int> f(NMAX + 1);
  f[NMAX] = binpow(fact[NMAX], MODULO - 2);

  for (int i = NMAX - 1; i >= 0; i--) {
    f[i] = (i + 1LL) * f[i + 1] % MODULO;
  }
  return f;
}();

void solve() {
  string s;
  cin >> s;

  vector<int> cnt(26, 0);
  for (char c : s) {
    cnt[c - 'a']++;
  }

  int res = fact[s.size()];

  for (int c : cnt) {
    res = 1LL * res * ifact[c] % MODULO;
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
