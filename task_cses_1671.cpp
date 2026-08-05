#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  // zero based id & weight
  vector<vector<pair<int, int>>> adj(n);

  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    v--;
    u--;
    adj[v].push_back(pair(u, w));
  }

  vector<ll> weight(n, 1e18);
  weight[0] = 0;

  // weight & zero based id
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  pq.push(pair(0, 0));

  while (!pq.empty()) {
    pair<ll, int> top = pq.top();
    pq.pop();

    if (top.first > weight[top.second]) {
      continue;
    }

    for (pair<int, int> to : adj[top.second]) {
      if (weight[to.first] > to.second + weight[top.second]) {
        weight[to.first] = to.second + weight[top.second];
        pq.push(pair(to.second + weight[top.second], to.first));
      }
    }
  }
  for (ll w : weight) {
    cout << w << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
