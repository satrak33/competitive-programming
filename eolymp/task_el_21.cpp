#include <algorithm>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i] << (i + 1 < v.size() ? ", " : "");
  }
  return os << "]";
}

template <typename T> ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  auto it = s.begin();
  while (it != s.end()) {
    os << *it;
    if (++it != s.end())
      os << ", ";
  }
  return os << "}";
}

template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  auto it = m.begin();
  while (it != m.end()) {
    os << it->first << ": " << it->second;
    if (++it != m.end())
      os << ", ";
  }
  return os << "}";
}

void dbg_out() { cerr << endl; }

template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\033[1;31m[" << __LINE__ << "] " << #__VA_ARGS__ << ":\033[0m",     \
      dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve() {
  float n, p;

  cin >> n >> p;
  priority_queue<float, vector<float>, greater<float>> pq;

  for (int i = 0; i < n; i++) {
    float m;
    cin >> m;

    pq.push(m);
  }

  while (pq.size() > 1) {
    float a, b, c;

    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();

    c = (a + b) * (1.00f - p / 100.00f);

    pq.push(c);
  }

  cout << fixed << setprecision(2) << pq.top();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();

  return 0;
}
