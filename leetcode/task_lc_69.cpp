#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int l = 0;
    int r = 46341;

    while (l < r) {
      int mid = l + (r - l) / 2;
      cout << "L: " << l << " M: " << mid << " R: " << r << "\n";
      if (mid * mid > x) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r - 1;
  }
};
