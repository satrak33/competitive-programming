#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
  ll n;
  cin >> n;

  ll sum = (n * (n + 1)) / 2;
  for (int i = 0; i < n - 1; i++) {
    int el;
    cin >> el;

    sum -= el;
  }
  cout << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();

  return 0;
}
