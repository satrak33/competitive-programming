#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  double sum = 0;
  for (int i = n; i >= 1; i--) {
    sum += 1.0 / i;

    if (sum > 0.5) {
      cout << i << "\n";
      return 0;
    }
  }
}
