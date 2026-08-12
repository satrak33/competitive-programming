#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void backtrack(vector<pair<int, int>> &best_path, int &best_l, int cur_l,
               vector<pair<int, int>> &path, vector<vector<int>> &towers,
               set<vector<vector<int>>> &visited) {
  if (cur_l >= best_l) {
    return;
  }
  if (towers[0].empty() && towers[1].empty()) {
    best_path = path;
    best_l = cur_l;
    return;
  }

  if (visited.count(towers)) {
    return;
  }
  visited.insert(towers);

  for (size_t i = 0; i < towers.size(); ++i) {
    if (towers[i].empty()) {
      continue;
    }

    for (size_t j = 0; j < towers.size(); ++j) {
      if (i == j) {
        continue;
      }

      if (!towers[j].empty() && towers[i].back() > towers[j].back()) {
        continue;
      }

      path.push_back({i, j});
      int disk = towers[i].back();
      towers[i].pop_back();
      towers[j].push_back(disk);

      backtrack(best_path, best_l, cur_l + 1, path, towers, visited);

      towers[j].pop_back();
      towers[i].push_back(disk);
      path.pop_back();
    }
  }

  visited.erase(towers);
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> towers(3);

  for (int i = n; i > 0; i--) {
    towers[0].push_back(i);
  }

  vector<pair<int, int>> path;
  vector<pair<int, int>> best_path;
  set<vector<vector<int>>> visited;

  int best_l = 1e9;
  int cur_l = 0;

  backtrack(best_path, best_l, cur_l, path, towers, visited);

  cout << best_path.size() << "\n";
  for (const auto &step : best_path) {
    cout << step.first + 1 << " " << step.second + 1 << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
