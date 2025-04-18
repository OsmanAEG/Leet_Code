#include<iostream>
#include<vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> products(nums.size(), 1);
    int start = 1;
    int end   = 1;

    for(int i = 0; i < nums.size(); ++i) {
      products[i] *= start;
      start *= nums[i];
    }

    for(int i = nums.size() - 1; i >= 0; --i) {
      products[i] *= end;
      end *= nums[i];
    }

    return products;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 4};

  const auto result = Solution().productExceptSelf(nums);
  for(const auto& num : result) std::cout << num << std::endl;

  return 0;
}