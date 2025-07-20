// LeetCode: 1

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, std::vector<int>> nums_map;

    for(int i = 0; i < nums.size(); ++i) {
      nums_map[nums[i]].push_back(i);
    }

    std::sort(nums.begin(), nums.end());

    int low_idx = 0;
    int high_idx = nums.size() - 1;

    while(low_idx < high_idx) {
      if(nums[low_idx] + nums[high_idx] < target) {
        ++low_idx;
      } else if(nums[low_idx] + nums[high_idx] > target) {
        --high_idx;
      } else {
        break;
      }
    }

    if(nums[low_idx] == nums[high_idx]) {
      return {nums_map[nums[low_idx]][0], nums_map[nums[low_idx]][1]};
    } else {
      return {nums_map[nums[low_idx]][0], nums_map[nums[high_idx]][0]};
    }
  }
};