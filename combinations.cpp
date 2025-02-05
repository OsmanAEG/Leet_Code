#include<vector>

class Solution {
public:
  void find_combinations(std::vector<std::vector<int>>& combinations,
                         std::vector<int> combination,
                         int i, int n, int k) {
    if(combination.size() == k) {
      combinations.push_back(combination);
    } else {
      for(int j = i; j <= n; ++j) {
        combination.push_back(j);
        find_combinations(combinations, combination, j + 1, n, k);
        combination.pop_back();
      }
    }
  }

  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> combinations;

    find_combinations(combinations, {}, 1, n, k);

    return combinations;
  }
};