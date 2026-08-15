#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int k, r;
  cin >> k >> r;

  int sh = 1;

  while ((k * sh) % 10 != r && (k * sh) % 10 != 0) {
    sh++;
  }

  cout << sh;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
