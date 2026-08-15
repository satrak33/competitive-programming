#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int n;

  cin >> n;

  int c = 0;
  while (n) {
    c += n / 5;
    n /= 5;
  }
  cout << c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
