#include<vector>

class Solution {
public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    long long sum = 0;
    int min_len = 1E6;

    bool found_sum = false;

    int low = 0;
    int high = 0;

    while(high < nums.size()) {
      sum += nums[high];

      while(sum >= target) {
        found_sum = true;
        const int len = high - low + 1;
        min_len = std::min(len, min_len);
        sum -= nums[low];
        ++low;
      }

      ++high;
    }

    if(found_sum) return min_len;
    else return 0;
  }
};