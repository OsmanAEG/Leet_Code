#include <algorithm>
#include <vector>

class Solution {
public:
  int maxAdjacentDistance(std::vector<int>& nums) {
    const auto N = nums.size();
    int max_diff = std::abs(nums[N-1]-nums[0]);

    for(int i = 1; i < nums.size(); ++i) {
      const auto diff = std::abs(nums[i] - nums[i-1]);
      max_diff = std::max(max_diff, diff);
    }

    return max_diff;
  }
};