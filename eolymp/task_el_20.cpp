#include <iostream>

using namespace std;

using ll = long long;

int get_sum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

void solve() {
  int n;
  cin >> n;

  int res = 0;

  while (n > 0) {
    res++;
    n -= get_sum(n);
  }
  cout << res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();

  return 0;
}
