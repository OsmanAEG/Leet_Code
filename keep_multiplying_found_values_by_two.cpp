// LeetCode: 2154

#include <set>
#include <vector>

class Solution {
public:
  int findFinalValue(std::vector<int>& nums, int original) {
    std::set<int> set;
    for(const auto& num : nums) set.insert(num);
    while(set.find(original) != set.end()) original *= 2;

    return original;
  }
};