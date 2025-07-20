#include<iostream>
#include<vector>

class Solution {
public:
  template<typename Vec_T, typename Vec_Vec_T>
  void make_permutations(Vec_T nums, Vec_T new_nums, Vec_Vec_T& permutations) {
    if(nums.size() == 0){
      permutations.push_back(new_nums);
      return;
    }

    for(int i = 0; i < nums.size(); ++i) {
      auto input_nums = nums;
      input_nums.erase(input_nums.begin() + i);
      new_nums.push_back(nums[i]);
      make_permutations(input_nums, new_nums, permutations);
      new_nums.pop_back();
    }
  }

  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> permutations;
    make_permutations(nums, {}, permutations);
    return permutations;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3};
  const auto result = Solution().permute(nums);

  for(const auto& vec : result) {
    std::cout << "[";
    for(int i = 0; i < vec.size(); ++i) {
      std::cout << vec[i];
      if(i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
  }

  return 0;
}