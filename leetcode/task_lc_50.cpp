using namespace std;

class Solution {
public:
  double myPow(double x, long long n) {
    double result = 1.0;
    bool negative = n < 0;

    if (negative) {
      n = -n;
    }

    while (n > 0) {
      if (n & 1) {
        result *= x;
      }
      x *= x;
      n >>= 1;
    }

    return negative ? 1.0 / result : result;
  }
};
