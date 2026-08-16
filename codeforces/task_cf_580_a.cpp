#include <algorithm>
#include <any>
#include <iostream>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  ll mx = 1;
  ll cm = 1;
  int pr;

  cin >> pr;
  n--;
  while (n--) {
    int cr;
    cin >> cr;

    // cout << "pr: " << pr << "\n";
    // cout << "cr: " << cr << "\n";
    // cout << "cm: " << cm << "\n";
    // cout << "mx: " << mx << "\n";
    // cout << "----------" << "\n";

    if (cr >= pr) {
      cm++;
    } else {
      mx = max(mx, cm);
      cm = 1;
    }
    pr = cr;
  }
  mx = max(mx, cm);
  cout << mx << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
