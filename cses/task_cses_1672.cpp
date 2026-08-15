#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  // 0-based index & weight
  vector<vector<pair<int, int>>> adj(n);

  vector<vector<ll>> di(n);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    a--;
    b--;

    adj[a].push_back(pair(b, c));
    adj[b].push_back(pair(a, c));
  }
  for (int k = 0; k < n; ++k) {
    vector<ll> weight(n, 1e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;

    weight[k] = 0;
    pq.push(pair(0, k));

    while (!pq.empty()) {
      pair<ll, int> pr = pq.top();
      pq.pop();

      int from = pr.second;
      ll wt = pr.first;

      if (weight[from] < wt) {
        continue;
      }

      for (int j = 0; j < adj[from].size(); ++j) {
        pair<int, int> prto = adj[from][j];
        int to = prto.first;
        int towt = prto.second;

        if (weight[to] > towt + weight[from]) {
          weight[to] = towt + weight[from];
          pq.push(pair(weight[to], to));
        }
      }
    }
    di[k] = weight;
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (di[a][b] != 1e18) {
      cout << di[a][b] << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
