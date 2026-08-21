#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int mid = l + (r - l) / 2;

      if (nums[mid] > nums[r]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    int offset = l;

    l = 0;
    r = nums.size() - 1;

    int res = -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      int real_mid = (mid + offset) % nums.size();
      int mid_el = nums[real_mid];

      if (mid_el == target) {
        res = real_mid;
        break;
      } else if (mid_el > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return res;
  }
};
