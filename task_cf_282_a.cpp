#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  int x = 0;
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;

    if (a.front() == '+' || a.back() == '+') {
      ++x;
    } else {
      x--;
    }
  }

  cout << x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
