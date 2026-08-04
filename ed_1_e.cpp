#include <cstdint>
#include <iostream>
#include <unordered_map>

using namespace std;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    return splitmix64(x + 0x9e3779b97f4a7c15);
  }
};

unordered_map<long long, long long, custom_hash> memo;
long long p, q, x, y;

long long get_A(long long i) {
  if (i <= 0) {
    return 1;
  }

  auto it = memo.find(i);
  if (it != memo.end()) {
    return it->second;
  }

  long long next1 = i / p - x;
  long long next2 = i / q - y;

  long long result = get_A(next1) + get_A(next2);
  memo[i] = result;

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;

  if (cin >> n >> p >> q >> x >> y) {
    cout << get_A(n) << "\n";
  }

  return 0;
}
