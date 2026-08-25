#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    if (beginWord == endWord) {
      return 1;
    }

    unordered_map<string, int> begin_dist;
    unordered_map<string, int> end_dist;

    begin_dist.reserve(wordList.size() * 2 + 1);
    end_dist.reserve(wordList.size() * 2 + 1);

    for (const string &word : wordList) {
      begin_dist[word] = -1;
      end_dist[word] = -1;
    }

    if (!begin_dist.contains(endWord)) {
      return 0;
    }

    begin_dist[beginWord] = 0;
    end_dist[beginWord] = -1;
    end_dist[endWord] = 0;

    queue<string> begin_q;
    queue<string> end_q;

    begin_q.push(beginWord);
    end_q.push(endWord);

    while (!begin_q.empty() && !end_q.empty()) {
      if (begin_q.size() <= end_q.size()) {
        int size = begin_q.size();

        while (size--) {
          string cur = begin_q.front();
          begin_q.pop();

          int dist = begin_dist[cur];

          for (int i = 0; i < cur.size(); ++i) {
            char old = cur[i];

            for (char c = 'a'; c <= 'z'; ++c) {
              if (c == old) {
                continue;
              }

              cur[i] = c;

              if (!begin_dist.contains(cur)) {
                continue;
              }

              if (end_dist[cur] != -1) {
                return dist + 1 + end_dist[cur] + 1;
              }

              if (begin_dist[cur] == -1) {
                begin_dist[cur] = dist + 1;
                begin_q.push(cur);
              }
            }

            cur[i] = old;
          }
        }
      } else {
        int size = end_q.size();

        while (size--) {
          string cur = end_q.front();
          end_q.pop();

          int dist = end_dist[cur];

          for (int i = 0; i < cur.size(); ++i) {
            char old = cur[i];

            for (char c = 'a'; c <= 'z'; ++c) {
              if (c == old) {
                continue;
              }

              cur[i] = c;

              if (!end_dist.contains(cur)) {
                continue;
              }

              if (begin_dist[cur] != -1) {
                return dist + 1 + begin_dist[cur] + 1;
              }

              if (end_dist[cur] == -1) {
                end_dist[cur] = dist + 1;
                end_q.push(cur);
              }
            }

            cur[i] = old;
          }
        }
      }
    }

    return 0;
  }
};
