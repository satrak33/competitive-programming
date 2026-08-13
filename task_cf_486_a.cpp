#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  if (n % 2 == 0) {
    cout << n / 2;
  } else {
    cout << -n / 2 - 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
