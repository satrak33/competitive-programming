#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string_view>
#include <type_traits>
#include <vector>

using namespace std;
using ll = long long;

void backtrack(int start, vector<int> &candidates, ll sum, ll &best_dif,
               const ll &total_sum, vector<bool> &path) {
  // cout << "----------\n";
  // cout << "sum: " << total_sum << "\n";
  // cout << "bd: " << best_dif << "\n";
  // cout << "a: " << sum << "\n";
  // cout << "b: " << total_sum - sum << "\n";
  // cout << "dif: " << abs(total_sum - sum - sum) << "\n";
  // vector<int> a;
  // vector<int> b;

  // ll a_sum = 0;
  // ll b_sum = 0;

  // for (int i = 0; i < path.size(); ++i) {
  //   if (path[i]) {
  //     a.push_back(candidates[i]);
  //     a_sum += candidates[i];
  //   } else {
  //     b.push_back(candidates[i]);
  //     b_sum += candidates[i];
  //   }
  // }
  // cout << "A: ";
  // for (auto el : a) {
  //   cout << el << " ";
  // }
  // cout << "\nSum: " << a_sum << "\n";

  // cout << "B: ";
  // for (auto el : b) {
  //   cout << el << " ";
  // }
  // cout << "\nSum: " << b_sum << "\n";

  // cout << "Dif: " << abs(a_sum - b_sum) << "\n\n";

  if (start == candidates.size()) {
    best_dif = min(best_dif, abs(total_sum - sum - sum));
    return;
  }

  path[start] = true;
  backtrack(start + 1, candidates, sum + candidates[start], best_dif, total_sum,
            path);
  path[start] = false;
  backtrack(start + 1, candidates, sum, best_dif, total_sum, path);
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll total_sum = 0;
  for (int i = 0; i < n; ++i) {
    total_sum += a[i];
  }
  ll best_dif = 1e18;
  vector<bool> path(n, false);
  backtrack(0, a, 0, best_dif, total_sum, path);
  cout << best_dif;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
