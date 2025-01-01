#include<iostream>
#include<vector>

class Solution {
public:
  int findClosestNumber(std::vector<int>& nums) {
    int closest = 0;
    int dist = 1e6;

    for(const auto& num : nums) {
      const auto dist_num = std::abs(num);

      if(dist_num < dist) {
        closest = num;
        dist = dist_num;
      }

      if(dist_num == dist) closest = (num > closest) ? closest = num : closest = closest;
    }

    return closest;
  }
};

int main() {
  std::vector<int> nums = {-4,-2,1,4,8};

  const auto result = Solution().findClosestNumber(nums);
  std::cout << result << std::endl;

  return 0;
}