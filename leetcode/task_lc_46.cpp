#include <vector>

using namespace std;

void backtrack(vector<int> &possible, vector<int> &current, vector<vector<int>> &result) {
  if (possible.empty()) {
    result.push_back(current);
    return;
  }

  for (int i = 0; i < possible.size(); ++i) {

    current.push_back(possible[i]);
    possible.erase(possible.begin() + i);
    backtrack(possible, current, result);
    possible.insert(possible.begin() + i, current.back());
    current.pop_back();
  }
}

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;

    backtrack(nums, current, result);

    return result;
  }
};
