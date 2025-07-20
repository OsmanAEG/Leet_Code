#include <algorithm>
#include <vector>

class Solution {
public:
  int partitionArray(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());

    int min_idx = 0;
    int max_idx = 0;

    int counter = 1;

    while(max_idx < nums.size()) {
      if(nums[max_idx] - nums[min_idx] > k) {
        ++counter;
        min_idx = max_idx;
      } else {
        ++max_idx;
      }
    }

    return counter;
  }
};