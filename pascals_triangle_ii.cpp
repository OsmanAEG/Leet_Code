#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> getRow(int rowIndex) {
    if(rowIndex == 0) return {{1}};
    if(rowIndex == 1) return {{1, 1}};

    std::vector<std::vector<int>> result;

    result.push_back({1});
    result.push_back({1, 1});

    int curr_row = 2;

    while(curr_row < rowIndex) {
      std::vector<int> row_result;

      row_result.push_back(1);

      for(int i = 1; i < curr_row; ++i) {
        row_result.push_back(result.back()[i-1] + result.back()[i]);
      }

      row_result.push_back(1);

      result.push_back(row_result);

      ++curr_row;
    }

    return result;
  }
};