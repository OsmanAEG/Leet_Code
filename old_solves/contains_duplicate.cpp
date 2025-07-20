#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> map;

    for(const auto& num : nums) {
      map[num] += 1;

      if(map[num] > 1) return true;
    }

    return false;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 1};
  const auto result = Solution().containsDuplicate(nums);

  std::cout << result << std::endl;
  return 0;
}