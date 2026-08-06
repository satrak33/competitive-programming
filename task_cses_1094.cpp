#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  ll c = 0;
  for (int i = 1; i < n; ++i) {
    if (x[i] < x[i - 1]) {
      c += x[i - 1] - x[i];
      x[i] += x[i - 1] - x[i];
    }
  }
  cout << c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
