#include<iostream>
#include<set>
#include<vector>

class Solution {
public:
  void find_subsets(std::set<std::vector<int>>& set_vecs, std::vector<int>& nums) {
    if(nums.size() == 0) return;

    for(int i = 0; i < nums.size(); ++i) {
      auto reduced_vec = nums;
      reduced_vec.erase(reduced_vec.begin() + i);
      set_vecs.insert(reduced_vec);
      find_subsets(set_vecs, reduced_vec);
    }
  }

  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::set<std::vector<int>> set_vecs;
    set_vecs.insert(nums);
    find_subsets(set_vecs, nums);

    return std::vector<std::vector<int>>(set_vecs.begin(), set_vecs.end());
  }
};

int main() {
  std::vector<int> nums = {1,2,3};
  const auto result = Solution().subsets(nums);

  for(const auto& vec : result) {
    std::cout << "[";
    for(int i = 0; i < vec.size(); ++i) {
      std::cout << vec[i] << ", ";
    }
    std::cout << "]" << std::endl;
  }

  return 0;
}