// LeetCode: 36

#include <unordered_set>
#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    int num_rows = board.size();
    int num_cols = board[0].size();

    for(int i = 0; i < num_rows; ++i) {
      std::unordered_set<int> set;

      for(int j = 0; j < num_cols; ++j) {
        const auto& c = board[i][j];

        if(c != '.' && set.find(c) != set.end()) {
          return false;
        } else if(c != '.') {
          set.insert(c);
        }
      }
    }

    for(int j = 0; j < num_cols; ++j) {
      std::unordered_set<int> set;

      for(int i = 0; i < num_rows; ++i) {
        const auto& c = board[i][j];

        if(c != '.' && set.find(c) != set.end()) {
          return false;
        } else if(c != '.') {
          set.insert(c);
        }
      }
    }

    for(int row_grid = 0; row_grid < 3; ++row_grid) {
      for(int col_grid = 0; col_grid < 3; ++col_grid) {
        std::unordered_set<int> set;

        for(int i = row_grid*3; i < row_grid*3 + 3; ++i) {
          for(int j = col_grid*3; j < col_grid*3 + 3; ++j) {
            const auto& c = board[i][j];

            if(c != '.' && set.find(c) != set.end()) {
              return false;
            } else if(c != '.') {
              set.insert(c);
            }
          }
        }
      }
    }

    return true;
  }
};