#include <vector>

using namespace std;

int modbinpow(int a, int b) {
  int result = 1;
  a %= 1337;
  while (b > 0) {
    if (b & 1) {
      result = result * a % 1337;
    }
    a = a * a % 1337;
    b >>= 1;
  }
  return result;
}

class Solution {
public:
  int superPow(int a, vector<int> &b) {
    int res = 1;
    for (auto el : b) {
      res = modbinpow(res, 10) * modbinpow(a, el) % 1337;
    }
    return res;
  }
};
