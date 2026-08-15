#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  array<int, 4> a;
  for (int i = 0; i < 4; ++i) {
    cin >> a[i];
  }

  int d;
  cin >> d;

  vector<bool> alive(d + 1, true);

  for (int i = 0; i < 4; ++i) {
    int el = a[i];
    for (int j = el; j <= d; j += el) {
      alive[j] = false;
    }
  }

  int sum = 0;
  for (int i = 0; i <= d; ++i) {
    // cout << i << "->" << alive[i] << "\n";
    sum += !alive[i];
  }

  cout << sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
