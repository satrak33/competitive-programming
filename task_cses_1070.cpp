#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1;
    return;
  }

  if (n < 4) {
    cout << "NO SOLUTION";
    return;
  }

  if (n == 4) {
    cout << "2 4 1 3";
    return;
  }

  for (int i = 0; i * 2 + 1 <= n; ++i) {
    cout << i * 2 + 1 << " ";
  }

  for (int i = 1; i * 2 <= n; ++i) {
    cout << i * 2 << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
