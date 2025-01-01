#include<iostream>
#include<vector>

class Solution {
public:
  template<typename Vector_T>
  int count_bitwise(Vector_T& nums) {
    int result = 0;
    for(const auto& num : nums) result |= num;
    return result;
  }

  template<typename Vector_T>
  void get_max_subsets(int& subsets, Vector_T& nums, int idx, int curr_or, const int result) {
    if(curr_or == result) ++subsets;

    for(int i = idx; i < nums.size(); ++i) {
      get_max_subsets(subsets, nums, i + 1, curr_or | nums[i], result);
    }
  }

  int countMaxOrSubsets(std::vector<int>& nums) {
    const auto result = count_bitwise(nums);
    int subsets = 0;
    get_max_subsets(subsets, nums, 0, 0, result);
    return subsets;
  }
};

int main() {
  std::vector<int> nums = {3,2,1,5};
  const auto result = Solution().countMaxOrSubsets(nums);
  std::cout << result << std::endl;
  return 0;
}