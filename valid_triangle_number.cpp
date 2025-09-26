// LeetCode: 611

#include <algorithm>
#include <vector>

class Solution {
public:
  bool is_valid_triangle(int a, int b, int c) {
    if(a + b > c) return true;
    else return false;
  }

  int triangleNumber(std::vector<int>& nums) {
    if(nums.size() < 3) return 0;

    int num_triplets = 0;

    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 2; ++i) {
      for(int j = i + 1; j < nums.size() - 1; ++j) {
        for(int k = j + 1; k < nums.size(); ++k) {
          const auto& a = nums[i];
          const auto& b = nums[j];
          const auto& c = nums[k];
          if(is_valid_triangle(a, b, c)) ++num_triplets;
        }
      }
    }

    return num_triplets;
  }
};