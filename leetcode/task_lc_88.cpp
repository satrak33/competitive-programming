#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int p1 = 0;
    int p2 = 0;
    int idx = 0;
    vector<int> res(n + m);

    while (idx < n + m) {
      int mn;
      if (p1 < m && p2 < n) {
        if (nums1[p1] < nums2[p2]) {
          mn = nums1[p1];
          p1++;
        } else {
          mn = nums2[p2];
          p2++;
        }
      } else if (p1 < m) {
        mn = nums1[p1];
        p1++;
      } else {
        mn = nums2[p2];
        p2++;
      }
      res[idx] = mn;
      idx++;
    }
    nums1 = res;
  }
};
