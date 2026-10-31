#include <vector>

using namespace std;

class Solution {
public:
  int superPow(int a, vector<int> &b) {
    a %= 1337;
    int res = 1;
    while (true) {
      bool empty = true;
      if (b.back() & 1) {
        res = res * a % 1337;
      }
      a = a * a % 1337;

      b.back() /= 2;
      if (b.back() != 0) {
        empty = false;
      }
      for (int i = static_cast<int>(b.size()) - 2; i >= 0; i--) {
        if (b[i] != 0) {
          empty = false;
        }
        if (b[i] & 1) {
          b[i + 1] += 5;
        }
        b[i] /= 2;
      }
      if (empty) {
        break;
      }
    }
    return res;
  }
};
