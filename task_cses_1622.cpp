#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void backtrack(string path, const string &candidates, vector<string> &results,
               vector<bool> &used) {
  if (path.size() == candidates.size()) {
    results.push_back(path);
    return;
  }
  for (int i = 0; i < candidates.size(); ++i) {
    if (used[i]) {
      continue;
    }
    if (i > 0 && candidates[i - 1] == candidates[i] && !used[i - 1]) {
      continue;
    }

    used[i] = true;
    path.push_back(candidates[i]);
    backtrack(path, candidates, results, used);
    path.pop_back();
    used[i] = false;
  }
}
void solve() {
  string a;
  cin >> a;

  sort(a.begin(), a.end());

  vector<string> results;
  vector<bool> used(a.size(), false);
  backtrack("", a, results, used);

  cout << results.size() << "\n";
  for (int i = 0; i < results.size(); ++i) {
    cout << results[i] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
