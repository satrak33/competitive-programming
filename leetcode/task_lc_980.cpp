#include <vector>

using namespace std;
//  1 - START
//  2 - END
//  0 - EMPTY
// -1 - WALL

vector<pair<int, int>> dx = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void backtrack(int &count, vector<vector<int>> &grid, int &free_cnt, pair<int, int> pos) {
  if (pos.first >= grid.size() || pos.first < 0) {
    return;
  }

  if (pos.second >= grid[0].size() || pos.second < 0) {
    return;
  }

  if (grid[pos.first][pos.second] == -1) {
    return;
  }

  if (grid[pos.first][pos.second] == 2) {
    if (free_cnt == 0) {
      count++;
    }
    return;
  }

  int old = grid[pos.first][pos.second];
  grid[pos.first][pos.second] = -1;
  free_cnt--;

  for (auto [h, k] : dx) {
    backtrack(count, grid, free_cnt, {pos.first + h, pos.second + k});
  }

  free_cnt++;
  grid[pos.first][pos.second] = old;
}

class Solution {
public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    int free_cnt = 1;
    pair<int, int> pos;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 0) {
          free_cnt++;
        }
        if (grid[i][j] == 1) {
          pos = {i, j};
        }
      }
    }

    int count = 0;

    backtrack(count, grid, free_cnt, pos);

    return count;
  }
};
