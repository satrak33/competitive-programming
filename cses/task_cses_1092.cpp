#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  ll sum = (n * (n + 1)) / 2;

  if (sum % 2 == 1) {
    cout << "NO";
    return;
  }

  set<int> set1;
  set<int> set2;

  ll target = sum / 2;
  for (int i = n; i >= 1; i--) {
    if (i <= target) {
      set1.insert(i);
      target -= i;
    } else {
      set2.insert(i);
    }
  }

  cout << "YES\n";
  cout << set1.size() << "\n";
  for (int x : set1) {
    cout << x << " ";
  }
  cout << "\n";

  cout << set2.size() << "\n";
  for (int x : set2) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
