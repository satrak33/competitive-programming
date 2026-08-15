#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void spf(vector<int> &primes) {
  for (int i = 2; i < primes.size(); ++i) {
    if (primes[i] != 0) {
      continue;
    }

    primes[i] = i;

    if (1LL * i * i >= primes.size()) {
      continue;
    }

    for (int j = i * i; j < primes.size(); j += i) {
      if (primes[j] == 0) {
        primes[j] = i;
      }
    }
  }
}

void solve() {
  int n;
  cin >> n;

  const int MAX = 1'000'000;
  vector<int> primes(MAX + 1);

  spf(primes);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    int ans = 1;

    while (x > 1) {
      int p = primes[x];
      int cnt = 0;

      while (x % p == 0) {
        x /= p;
        ++cnt;
      }

      ans *= cnt + 1;
    }

    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
