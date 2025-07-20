#include<vector>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    int low = 0;
    int high = 0;

    int n = 0;

    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return 1;

    while(high < nums.size()) {
      while(high < nums.size() && nums[low] == nums[high]) ++high;
      low = high;
      ++n;
      if(high < nums.size()) nums[n] = nums[low];
    }

    return n;
  }
};