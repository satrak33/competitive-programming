#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) return {-1, -1};

    int l, r;
    l = 0;
    r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    int start = l;
    if (nums[start] != target) {
      return {-1, -1};
    }

    l = 0;
    r = nums.size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] <= target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    int endd = l - 1;

    return {start, endd};
  }
};
