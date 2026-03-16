// LeetCode: 2239

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int findClosestNumber(std::vector<int>& nums) {
    int min_val = nums[0];
    int min_diff = std::abs(min_val);

    for(int i = 0; i < nums.size(); ++i) {
      const auto val  = nums[i];
      const auto diff = std::abs(nums[i]);

      if(diff == min_diff && val > min_val) {
        min_val = val;
      } else if(diff < min_diff) {
        min_val = val;
        min_diff = diff;
      }
    }

    return min_val;
  }
};