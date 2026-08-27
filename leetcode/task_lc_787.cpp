#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max();

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto &flight : flights) {
      int from = flight[0];
      int to = flight[1];
      int price = flight[2];
      graph[from].push_back({price, to});
    }

    vector<vector<int>> prices(n, vector<int>(k + 2, INF));
    prices[src][0] = 0;

    priority_queue<
      tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>
      pq;
    pq.push({0, src, 0});

    while (!pq.empty()) {
      auto [price, city, stops] = pq.top();
      pq.pop();
      cout << "price: " << price << " city: " << city << " stops: " << stops << "\n";

      if (price > prices[city][stops]) {
        continue;
      }

      if (city == dst) {
        return price;
      }

      if (stops == k + 1) {
        continue;
      }

      for (auto [price_to, to] : graph[city]) {
        int new_price = price + price_to;
        int new_stops = stops + 1;

        if (new_price < prices[to][new_stops]) {
          prices[to][new_stops] = new_price;
          cout << "price: " << "from: " << city << " to: " << to << " -> " << prices[to][new_stops]
               << "\n";
          pq.push({new_price, to, new_stops});
        }
      }
    }

    return -1;
  }
};
