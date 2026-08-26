#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numBusesToDestination(
    vector<vector<int>> &routes, int source, int target
  ) {
    if (source == target) {
      return 0;
    }

    unordered_map<int, vector<int>> stops_to_buses;
    stops_to_buses.reserve(10000);

    for (int i = 0; i < routes.size(); ++i) {
      for (int stop : routes[i]) {
        stops_to_buses[stop].push_back(i);
      }
    }
    unordered_set<int> visited_stops;
    unordered_set<int> visited_buses;

    queue<int> stops_q;
    stops_q.push(source);
    visited_stops.insert(source);

    int buses = 0;

    while (!stops_q.empty()) {
      int size = stops_q.size();
      buses++;
      while (size--) {
        int cur_stop = stops_q.front();
        stops_q.pop();

        for (auto bus : stops_to_buses[cur_stop]) {
          if (visited_buses.contains(bus)) {
            continue;
          }
          visited_buses.insert(bus);
          for (auto stop : routes[bus]) {
            if (visited_stops.contains(stop)) {
              continue;
            }
            stops_q.push(stop);
            visited_stops.insert(stop);

            if (stop == target) {
              return buses;
            }
          }
        }
      }
    }
    return -1;
  }
};
