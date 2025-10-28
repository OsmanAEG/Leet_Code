// LeetCode: 3354

#include <algorithm>
#include <vector>

class Solution {
public:
  bool testing_selection(std::vector<int> nums, int curr, bool dir_right) {
    while(curr >= 0 && curr <= nums.size() - 1) {
      if(nums[curr] == 0) {
        if(dir_right) ++curr;
        else --curr;
      } else if(nums[curr] > 0) {
        nums[curr] -= 1;
        dir_right = !dir_right;

        if(dir_right) ++curr;
        else --curr;
      }
    }

    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] != 0) return false;
    }

    return true;
  }

  int countValidSelections(std::vector<int>& nums) {
    int num_valid = 0;

    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] == 0) {
        if(testing_selection(nums, i, true))  ++ num_valid;
        if(testing_selection(nums, i, false)) ++ num_valid;
      }
    }

    return num_valid;
  }
};