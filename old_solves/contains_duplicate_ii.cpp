#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int, std::vector<int>> map;

    for(int i = 0; i < nums.size(); ++i){
      for(int j = 0; j < map[nums[i]].size(); ++j){
        if(std::abs(i-map[nums[i]][j]) <= k) return true;
      }

      map[nums[i]].push_back(i);
    }

    return false;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3, 1};
  int k = 3;
  const auto result = Solution().containsNearbyDuplicate(nums, k);

  std::cout << result << std::endl;
}