#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int openLock(vector<string> &deadends, string target) {
    if (target == "0000") {
      return 0;
    }

    vector<int> path_start(10000, -1);
    vector<int> path_target(10000, -1);

    for (const auto &deadend : deadends) {
      if (deadend == "0000" || deadend == target)
        return -1;

      int idx = stoi(deadend);
      path_start[idx] = -2;
      path_target[idx] = -2;
    }

    int target_id = stoi(target);

    if (path_start[0] == -2 || path_target[target_id] == -2)
      return -1;

    path_start[0] = 0;
    path_target[target_id] = 0;

    queue<int> start_q;
    queue<int> target_q;

    start_q.push(0);
    target_q.push(target_id);

    const int weights[] = {1000, 100, 10, 1};

    while (!start_q.empty() || !target_q.empty()) {
      if (!start_q.empty()) {
        int cur = start_q.front();
        start_q.pop();

        for (int i = 0; i < 4; ++i) {
          int weight = weights[i];
          int digit = (cur / weight) % 10;

          int next_p = cur + (digit == 9 ? -9 * weight : weight);
          int next_m = cur + (digit == 0 ? 9 * weight : -weight);

          if (path_start[next_p] == -1) {
            path_start[next_p] = path_start[cur] + 1;

            if (path_target[next_p] >= 0)
              return path_start[next_p] + path_target[next_p];

            start_q.push(next_p);
          }

          if (path_start[next_m] == -1) {
            path_start[next_m] = path_start[cur] + 1;

            if (path_target[next_m] >= 0)
              return path_start[next_m] + path_target[next_m];

            start_q.push(next_m);
          }
        }
      }

      if (!target_q.empty()) {
        int cur = target_q.front();
        target_q.pop();

        for (int i = 0; i < 4; ++i) {
          int weight = weights[i];
          int digit = (cur / weight) % 10;

          int next_p = cur + (digit == 9 ? -9 * weight : weight);
          int next_m = cur + (digit == 0 ? 9 * weight : -weight);

          if (path_target[next_p] == -1) {
            path_target[next_p] = path_target[cur] + 1;

            if (path_start[next_p] >= 0)
              return path_start[next_p] + path_target[next_p];

            target_q.push(next_p);
          }

          if (path_target[next_m] == -1) {
            path_target[next_m] = path_target[cur] + 1;

            if (path_start[next_m] >= 0)
              return path_start[next_m] + path_target[next_m];

            target_q.push(next_m);
          }
        }
      }
    }

    return -1;
  }
};
