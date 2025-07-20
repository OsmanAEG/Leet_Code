#include<iostream>
#include<vector>

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    const int num_rows = matrix.size();
    const int num_cols = matrix[0].size();

    std::vector<int> spiral(num_rows*num_cols);
    int entry = 0;

    int i_min = 0;
    int j_min = 0;
    int i_max = num_cols - 1;
    int j_max = num_rows - 1;

    char dir = 'r';

    while(entry < num_rows*num_cols){
      if(dir == 'r') {
        for(int i = i_min; i <= i_max; ++i) {
          spiral[entry] = matrix[j_min][i];
          ++entry;
        }
        j_min += 1;
        dir = 'd';
      }else if(dir == 'd') {
        for(int j = j_min; j <= j_max; ++j) {
          spiral[entry] = matrix[j][i_max];
          ++entry;
        }
        i_max -= 1;
        dir = 'l';
      }else if(dir == 'l') {
        for(int i = i_max; i >= i_min; --i) {
          spiral[entry] = matrix[j_max][i];
          ++entry;
        }
        j_max -= 1;
        dir = 'u';
      }else {
        for(int j = j_max; j >= j_min; --j) {
          spiral[entry] = matrix[j][i_min];
          ++entry;
        }
        i_min += 1;
        dir = 'r';
      }
    }

    return spiral;
  }
};

int main() {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  const auto result = Solution().spiralOrder(matrix);

  for(int i = 0; i < result.size(); ++i) {
    std::cout << result[i] << std::endl;
  }

  return 0;
}