#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
    std::vector<std::vector<int>> divided_array;

    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i += 3) {
      if(nums[i+1]-nums[i] > k)   return {};
      if(nums[i+2]-nums[i] > k)   return {};
      if(nums[i+2]-nums[i+1] > k) return {};

      std::vector<int> sub_nums = {nums[i], nums[i+1], nums[i+2]};
      divided_array.push_back(sub_nums);
    }

    return divided_array;
  }
};