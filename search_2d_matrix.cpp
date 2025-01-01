#include<iostream>
#include<vector>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int idx_1_low  = 0;
    int idx_1_high = matrix.size() - 1;
    int i = 0;

    while(idx_1_low <= idx_1_high) {
      i = (idx_1_low + idx_1_high)/2;

      if(matrix[i][0] < target) idx_1_low = i + 1;
      else if(matrix[i][0] > target) idx_1_high = i - 1;
      else return true;
    }

    if(idx_1_high < 0) return false;
    else i = idx_1_high;

    int idx_2_low  = 0;
    int idx_2_high = matrix[i].size() - 1;
    int j = 0;

    while(idx_2_low <= idx_2_high) {
      j = (idx_2_low + idx_2_high)/2;

      if(matrix[i][j] < target) idx_2_low = j + 1;
      else if(matrix[i][j] > target) idx_2_high = j - 1;
      else return true;
    }

    return false;
  }
};

int main() {
  std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
  const int target = 11;

  const auto result = Solution().searchMatrix(matrix, target);
  std::cout << result << std::endl;

  return 0;
}