#include <iostream>

using namespace std;
using ll = long long;

int binpow(int a, int b, int m) {
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
void solve() {
  int n;
  cin >> n;

  cout << binpow(1378, n, 10) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
