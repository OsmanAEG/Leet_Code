// LeetCode: 238

#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> products(nums.size(), 1);

    int mult = 1;

    for(int i = 0; i < nums.size(); ++i) {
      products[i] *= mult;
      mult *= nums[i];
    }

    mult = 1;

    for(int i = nums.size() - 1; i >= 0; --i) {
      products[i] *= mult;
      mult *= nums[i];
    }

    return products;
  }
};