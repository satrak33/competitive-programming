#include <vector>

using namespace std;
using ll = long long;

int binpow(ll a, ll b, int m) {
  a %= m;
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = 1LL * res * a % m;
    }
    a = 1LL * a * a % m;
    b >>= 1;
  }
  return res;
}

const int MODULO = (int)1e9 + 7;
const int NMAX = (int)1e6;

vector<int> fact = []() {
  vector<int> f(NMAX + 1);
  f[0] = 1;
  for (int i = 1; i < f.size(); ++i) {
    // i! = i * (i-1)!
    f[i] = 1LL * f[i - 1] * i % MODULO;
  }
  return f;
}();

vector<int> ifact = []() {
  vector<int> f(NMAX + 1);
  f[NMAX] = binpow(fact[NMAX], MODULO - 2, MODULO);
  for (int i = NMAX - 1; i >= 0; i--) {
    // 1/i! = (i + 1) * 1/(i+1)!
    f[i] = (i + 1LL) * f[i + 1] % MODULO;
  }
  return f;
}();
