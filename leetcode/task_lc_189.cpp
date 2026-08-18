#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
public:
  int gcd(int a, int b) {
    while (b) {
      a %= b;
      swap(a, b);
    }
    return a;
  }

  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    if (k == 0)
      return;

    int cycles = gcd(n, k);
    for (int start = 0; start < cycles; ++start) {
      int current = start;
      int prev = nums[start];
      do {
        int next_idx = (current + k) % n;
        swap(nums[next_idx], prev);
        current = next_idx;
      } while (current != start);
    }
  }
};
