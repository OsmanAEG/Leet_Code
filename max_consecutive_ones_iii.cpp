#include<vector>

class Solution {
public:
  int longestOnes(std::vector<int>& nums, int k) {
    int flipped = 0;
    int max_len = 0;

    int low = 0;
    int high = 0;

    while(high < nums.size()) {
      if(nums[high] == 0) ++flipped;

      while(flipped > k) {
        if(nums[low] == 0) --flipped;
        ++low;
      }

      max_len = std::max(high - low + 1, max_len);
      ++high;
    }

    return max_len;
  }
};