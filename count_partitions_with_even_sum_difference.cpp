// LeetCode: 3342

#include <vector>

class Solution {
public:
  int countPartitions(std::vector<int>& nums) {
    int num_partitions = 0;

    int sum_left  = 0;
    int sum_right = 0;

    for(const auto& num : nums) sum_right += num;

    for(int i = 0; i < nums.size() - 1; ++i) {
      sum_left  += nums[i];
      sum_right -= nums[i];

      const auto diff = sum_right - sum_left;

      if(diff%2 == 0) ++num_partitions;
    }

    return num_partitions;
  }
};