#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 0;
    int fast = 1;

    while (fast < nums.size()) {
      if (fast - slow == 2 && nums[slow] == nums[fast]) {
        while (fast < nums.size() && nums[slow] == nums[fast]) {
          nums.erase(nums.begin() + fast);
        }
        slow = fast;
        fast++;
      } else if (nums[slow] != nums[fast]) {
        slow++;
        fast++;
      } else {
        fast++;
      }
    }

    return nums.size();
  }
};
