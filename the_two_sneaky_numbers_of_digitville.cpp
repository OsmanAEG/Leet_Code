// LeetCode: 3289

#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int> getSneakyNumbers(std::vector<int>& nums) {
    std::unordered_set<int> digits;
    std::vector<int> extra_digits;

    for(const auto& num : nums) {
      if(digits.find(num) != digits.end()) extra_digits.push_back(num);
      else digits.insert(num);
    }

    return extra_digits;
  }
};