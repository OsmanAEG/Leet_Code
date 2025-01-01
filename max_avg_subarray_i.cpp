#include<vector>

class Solution {
public:
  double findMaxAverage(std::vector<int>& nums, int k) {
    int left  = 0;
    int right = k - 1;

    double dk = k;

    int sum = 0;

    for(int i = 0; i < k; ++i) sum += nums[i];

    double max_avg = sum/dk;

    while(right < nums.size() - 1) {
      ++left;
      ++right;

      sum += nums[right] - nums[left - 1];
      max_avg = std::max(max_avg, sum/dk);
    }

    return max_avg;
  }
};