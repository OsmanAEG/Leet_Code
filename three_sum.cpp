// LeetCode: 15

#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> valid_sums;

    for(int low = 0; low < nums.size() - 1; ++low) {
      int mid = low + 1;
      int high = nums.size() - 1;

      if(low > 0 && nums[low] == nums[low-1]) continue;

      while(mid < high) {
        const auto sum = nums[low] + nums[mid] + nums[high];
        if(sum > 0) {
          --high;
        } else if(sum < 0) {
          ++mid;
        } else {
          valid_sums.push_back({nums[low], nums[mid], nums[high]});
          ++mid;
          --high;
          while(nums[mid]  == nums[mid - 1]  && mid  < high) ++mid;
          while(nums[high] == nums[high + 1] && high > mid)  --high;
        }
      }
    }

    return valid_sums;
  }
};