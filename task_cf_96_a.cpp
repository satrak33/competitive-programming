#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  string s;
  cin >> s;

  int cnt = 1;
  bool dngr = false;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      cnt = 1;
    }

    if (cnt >= 7) {
      dngr = true;
      break;
    }
  }
  if (dngr) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
