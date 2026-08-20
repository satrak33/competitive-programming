#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MODULO = (int)1e9 + 7;
const int MAXN = (int)1e6;

int binpow(int a, int b) {
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
  vector<int> f(MAXN + 1);
  f[0] = 1;
  for (int i = 1; i < f.size(); ++i) {
    f[i] = 1LL * f[i - 1] * i % MODULO;
  }
  return f;
}();

vector<int> ifact = []() {
  vector<int> f(MAXN + 1);
  f[MAXN] = binpow(fact[MAXN], MODULO - 2);

  for (int i = MAXN - 1; i >= 0; i--) {
    f[i] = (i + 1LL) * f[i + 1] % MODULO;
  }
  return f;
}();

int c(int n, int k) {
  return 1LL * fact[n] * ifact[k] % MODULO * ifact[n - k] % MODULO;
}

void solve() {
  int a, b;
  cin >> a >> b;

  cout << c(a, b) << "\n";
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
