#include <algorithm>
#include <string>
#include <vector>

using namespace std;
vector<pair<int, int>> dim = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0},
};

bool check(vector<vector<char>> &board, const string &word, int &index, pair<int, int> pos) {
  if (word.size() == index) {
    index = 0;
    return true;
  }

  for (int i = 0; i < 4; i++) {
    int next_row = pos.first + dim[i].first;
    int next_col = pos.second + dim[i].second;
    if ((next_row >= 0 && next_row < board.size()) &&
        (next_col >= 0 && next_col < board[0].size())) {
      if (board[next_row][next_col] == word[index]) {
        char old = board[next_row][next_col];
        board[next_row][next_col] = '!';

        index++;
        if (check(board, word, index, {next_row, next_col})) {
          return true;
        }
        index--;
        board[next_row][next_col] = old;
      }
    }
  }

  return false;
}

class Solution {
public:
  bool exist(vector<vector<char>> &board, string &word) {
    char start = word[0];
    vector<int> counter(2, 0);

    for (auto w : board) {
      for (char x : w) {
        if (x == word[0]) {
          counter[0]++;
        } else if (x == word.back()) {
          counter[1]++;
        }
      }
    }

    if (counter[0] >= counter[1]) {
      reverse(word.begin(), word.end());
    }
    int index = 1;

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == word[0]) {
          char old = board[i][j];
          board[i][j] = '!';
          if (check(board, word, index, {i, j})) {
            return true;
          }
          board[i][j] = old;
        }
      }
    }

    return false;
  }
};
