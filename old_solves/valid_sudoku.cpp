#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    for(int i = 0; i < 9; ++i) {
      std::unordered_map<char, int> map_rows;
      std::unordered_map<char, int> map_cols;

      for(int j = 0; j < 9; ++j) {
        const auto& c_rows = board[i][j];
        const auto& c_cols = board[j][i];
        if(c_rows != '.') map_rows[c_rows] += 1;
        if(c_cols != '.') map_cols[c_cols] += 1;
        if(map_rows[c_rows] > 1) return false;
        if(map_cols[c_cols] > 1) return false;
      }
    }

    for(int sj = 0; sj < 9; sj += 3) {
      for(int si = 0; si < 9; si += 3) {
        std::unordered_map<char, int> my_map;

        for(int j = 0; j < 3; ++j) {
          for(int i = 0; i < 3; ++i) {
            const auto& c = board[i + si][j + sj];
            if(c != '.') my_map[c] += 1;
            if(my_map[c] > 1) return false;
          }
        }
      }
    }

    return true;
  }
};

int main() {
  std::vector<std::vector<char>> input = {{'5','3','.','.','7','.','.','.','.'},
                                          {'6','.','.','1','9','5','.','.','.'},
                                          {'.','9','8','.','.','.','.','6','.'},
                                          {'8','.','.','.','6','.','.','.','3'},
                                          {'4','.','.','8','.','3','.','.','1'},
                                          {'7','.','.','.','2','.','.','.','6'},
                                          {'.','6','.','.','.','.','2','8','.'},
                                          {'.','.','.','4','1','9','.','.','5'},
                                          {'.','.','.','.','8','.','.','7','9'}};

  const auto result = Solution().isValidSudoku(input);
  std::cout << result << std::endl;
}