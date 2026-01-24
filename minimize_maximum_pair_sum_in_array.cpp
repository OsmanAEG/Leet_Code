// LeetCode: 1877

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int minPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int max = INT_MIN;

    int l = 0;
    int h = nums.size() - 1;

    while(l < h) {
      max = std::max(max, nums[l] + nums[h]);
      ++l;
      --h;
    }

    return max;
  }
};