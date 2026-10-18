#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int max_step = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (i <= max_step) {
        max_step = max(max_step, i + nums[i]);
      } else {
        return false;
      }
    }

    return true;
  }
};
