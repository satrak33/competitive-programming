#include <iostream>
#include <string>

using namespace std;

void solve() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    if (tolower(s[0]) == 'y' && tolower(s[1]) == 'e' && tolower(s[2]) == 's') {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
