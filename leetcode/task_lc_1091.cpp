#include <queue>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();

    if (grid[0][0] || grid[n - 1][n - 1])
      return -1;

    static constexpr int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};

    queue<pair<int, int>> q;
    q.push({0, 0});

    vector<vector<bool>> visited(n, vector<bool>(n));
    visited[0][0] = true;

    int dist = 1;

    while (!q.empty()) {
      int levelSize = q.size();

      while (levelSize--) {
        auto [r, c] = q.front();
        q.pop();

        if (r == n - 1 && c == n - 1)
          return dist;

        for (auto &[dr, dc] : dirs) {
          int nr = r + dr;
          int nc = c + dc;

          if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;

          if (grid[nr][nc] || visited[nr][nc])
            continue;

          visited[nr][nc] = true;
          q.push({nr, nc});
        }
      }

      ++dist;
    }

    return -1;
  }
};
