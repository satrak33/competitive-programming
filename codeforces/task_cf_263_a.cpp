#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  bool x;
  for (int i = 1; i < 6; ++i) {
    for (int j = 1; j < 6; ++j) {
      cin >> x;
      if (x) {
        cout << abs(3 - i) + abs(3 - j);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
