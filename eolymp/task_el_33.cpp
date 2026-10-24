#include <iostream>
#include <vector>

using namespace std;

int MAX = 500005;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, b;
  cin >> a >> b;

  vector<bool> primes(MAX, true);
  primes[0] = primes[1] = false;

  for (int i = 2; i * i < MAX; i++) {
    if (!primes[i]) {
      continue;
    }

    for (int j = i * i; j < MAX; j += i) {
      primes[j] = false;
    }
  }

  int cnt = 0;
  bool is_cool;
  int ch;
  int r;
  for (int i = a; i <= b; i++) {

    if (primes[i]) {
      r = 00;
      is_cool = true;
      ch = i;
      while (ch > 0) {
        if (ch % 10 == 1) {
          if (r == 3) {
            is_cool = false;
            break;
          }
        }
        r = ch % 10;
        ch /= 10;
      }

      if (is_cool) {
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
}
