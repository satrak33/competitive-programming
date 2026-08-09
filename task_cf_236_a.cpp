#include <iostream>
#include <set>

using namespace std;
using ll = long long;

void solve() {
  string nick;
  cin >> nick;

  set<char> us(nick.begin(), nick.end());

  if (us.size() % 2 == 1) {
    cout << "IGNORE HIM!";
  } else {
    cout << "CHAT WITH HER!";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
