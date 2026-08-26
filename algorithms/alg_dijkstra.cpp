#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::max();

vector<ll> dijkstra(int n, const vector<vector<pair<int, int>>> &graph, int start) {
  vector<ll> dist(n, INF);

  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (d != dist[v]) {
      continue;
    }

    for (auto [t, w] : graph[v]) {
      if (dist[t] > d + w) {
        dist[t] = d + w;
        pq.push({dist[t], t});
      }
    }
  }

  return dist;
}
