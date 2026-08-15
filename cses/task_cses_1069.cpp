#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

void solve() {
  string a;
  cin >> a;

  int mx = 0;
  int crmx = 0;

  for (int i = 0; i < a.size() - 1; ++i) {
    if (a[i] == a[i + 1]) {
      ++crmx;
    } else {
      mx = max(mx, crmx);
      crmx = 0;
    }
  }
  mx = max(mx, crmx);

  cout << mx + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
