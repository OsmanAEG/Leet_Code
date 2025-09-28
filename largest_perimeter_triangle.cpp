// LeetCode: 976

#include <algorithm>
#include <vector>

class Solution {
public:
  bool is_valid_triangle(int a, int b, int c) {
    if(b + c > a) return true;
    else return false;
  }

  int calculate_perimeter(int a, int b, int c) {
    return a + b + c;
  }

  int largestPerimeter(std::vector<int>& nums) {
    int max = 0;
    std::sort(nums.rbegin(), nums.rend());

    for(int i = 0; i < nums.size() - 2; ++i) {
      if(is_valid_triangle(nums[i], nums[i+1], nums[i+2])) {
        max = std::max(max, calculate_perimeter(nums[i], nums[i+1], nums[i+2]));
        break;
      }
    }

    return max;
  }
};