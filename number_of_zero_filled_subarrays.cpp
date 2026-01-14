// LeetCode 2348

#include <vector>

class Solution {
public:
  long long zeroFilledSubarray(std::vector<int>& nums) {
    long long num = 0;

    long long stretch = 0;
    bool in_stretch = false;

    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] == 0 && in_stretch == false) {
        ++stretch;
        in_stretch = true;
      } else if(nums[i] == 0 && in_stretch == true) {
        ++stretch;
      } else {
        num += stretch*(stretch + 1)/2;
        in_stretch = false;
        stretch = 0;
      }
    }

    num += stretch*(stretch + 1)/2;

    return num;
  }
};