// LeetCode: 74

#include <iostream>
#include <vector>

class Solution {
public:
  bool found_target(std::vector<int>& row, int target) {
    int low = 0;
    int high = row.size() - 1;

    while(low <= high) {
      int mid = (low + high)/2;

      if(row[mid] < target) {
        low = mid + 1;
      } else if(row[mid] > target) {
        high = mid - 1;
      } else {
        return true;
      }
    }

    return false;
  }

  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    const int m = matrix.size();
    const int n = matrix[0].size();

    for(int i = 0; i < m; ++i) {
      auto result = found_target(matrix[i], target);

      if(result) return result;
    }

    return false;
  }
};