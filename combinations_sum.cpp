#include <vector>

class Solution {
public:
  void find_valid_combos(std::vector<int>& candidates,
                         std::vector<std::vector<int>>& valid_combos,
                         std::vector<int> combo,
                         int idx,
                         int target) {
    const int n = candidates.size();

    int sum = 0;
    for(const auto& num : combo) sum += num;

    if(sum == target) {
      valid_combos.push_back(combo);
    } else if(sum > target){
      return;
    } else {
      for(int i = idx; i < n; ++i) {
        combo.push_back(candidates[i]);
        find_valid_combos(candidates, valid_combos, combo, i, target);
        combo.pop_back();
      }
    }
  }

  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> valid_combos;
    find_valid_combos(candidates, valid_combos, {}, 0, target);
    return valid_combos;
  }
};