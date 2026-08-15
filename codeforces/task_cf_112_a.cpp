#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve() {
  string a;
  string b;

  cin >> a >> b;

  for (int i = 0; i < a.size(); ++i) {
    a[i] = tolower(static_cast<unsigned char>(a[i]));
    b[i] = tolower(static_cast<unsigned char>(b[i]));
  }

  if (a < b) {
    cout << -1 << "\n";
  } else if (a > b) {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
