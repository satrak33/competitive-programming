#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    if (n % 3 == 0) {
      cout << "Second\n";
    } else {
      cout << "First\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
