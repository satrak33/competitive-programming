#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  while (n--) {
    int x;
    cin >> x;

    int divs = 0;

    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        if (i * i == x)
          divs += 1;
        else
          divs += 2;
      }
    }
    cout << divs << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
