#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
  int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> my_map;
    std::vector<int> max(2);

    for(auto& num : nums) my_map[num] += 1;

    for(auto it = my_map.begin(); it != my_map.end(); ++it) {
      if(it->second > max[1]) {
        max[1] = it->second;
        max[0] = it->first;
      }
    }

    return max[0];
  }
};

int main() {
  std::vector<int> nums = {3,2,3};

  const auto result = Solution().majorityElement(nums);
  std::cout << result << std::endl;

  return 0;
}