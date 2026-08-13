#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  string a;
  cin >> a;

  vector<int> cnt(26, 0);
  for (char c : a) {
    cnt[c - 'A']++;
  }

  int odd_cnt = 0;
  int odd_idx = -1;

  for (int i = 0; i < 26; ++i) {
    if (cnt[i] % 2 == 1) {
      odd_cnt++;
      odd_idx = i;
    }
  }

  if (odd_cnt > 1) {
    cout << "NO SOLUTION";
    return;
  }

  string half = "";
  for (int i = 0; i < 26; ++i) {
    half.append(cnt[i] / 2, static_cast<char>(i + 'A'));
  }

  string result = half;
  if (odd_idx != -1) {
    result += static_cast<char>(odd_idx + 'A');
  }

  string right_half = half;
  reverse(right_half.begin(), right_half.end());
  result += right_half;

  cout << result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
