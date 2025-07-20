#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> diff_map;

    for(int i = 0; i < nums.size(); ++i) {
      const auto diff = target - nums[i];

      if(diff_map.find(diff) != diff_map.end()) return {i, diff_map[diff]};
      else diff_map[nums[i]] = i;
    }

    return {};
  }
};

int main() {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  const auto result = Solution().twoSum(nums, target);

  std::cout << "{" << result[0] << ", " << result[1] << "}" << std::endl;

  return 0;
}