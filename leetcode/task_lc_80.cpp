#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 2;
    int fast = 2;
    int cnt = min(static_cast<int>(nums.size()), 2);

    while (fast < nums.size()) {
      if (nums[fast] == nums[slow - 2]) {
        fast++;
      } else {
        nums[slow] = nums[fast];
        slow++;
        fast++;
        cnt++;
      }
    }

    return cnt;
  }
};
