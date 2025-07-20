#include <algorithm>
#include <vector>

class Solution {
public:
  int maximumDifference(std::vector<int>& nums) {
    int i = 0;
    int j = 1;

    int max_diff = -1;

    while(j < nums.size()) {
      const int diff = nums[j] - nums[i];

      if(diff != 0) {
        max_diff = std::max(diff, max_diff);
      }

      if(j - i == 1) {
        ++j;
        i = 0;
      } else {
        ++i;
      }
    }

    return max_diff;
  }
};