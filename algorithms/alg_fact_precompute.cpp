#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void precompute(vector<int> &fact, int mod) {
  fact[0] = 1;
  for (ll i = 1; i < fact.size(); ++i) {
    fact[i] = i * fact[i - 1] % mod;
  }
}
