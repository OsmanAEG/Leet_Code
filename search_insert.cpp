#include<vector>

class Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    int low  = 0;
    int high = nums.size() - 1;

    while(low <= high) {
      const int mid = (low + high)/2;

      if(nums[mid] < target) low = mid + 1;
      else high = mid - 1;
    }

    return low;
  }
};