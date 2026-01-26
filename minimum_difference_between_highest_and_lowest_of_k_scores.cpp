// LeetCode: 1984

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int minimumDifference(std::vector<int>& nums, int k) {
    if(k == 1) return 0;

    int l = 0;
    int h = l + k - 1;

    int min_diff = INT_MAX;

    std::sort(nums.begin(), nums.end());

    while(h < nums.size()) {
      min_diff = std::min(nums[h] - nums[l], min_diff);

      ++l;
      ++h;
    }

    return min_diff;
  }
};