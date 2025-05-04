#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
  int sumOfFlooredPairs(std::vector<int>& nums) {
    std::map<int, int> nums_map;

    int sum = 0;

    for(const auto& num : nums) nums_map[num] += 1;

    for(auto it = nums_map.rbegin(); it != nums_map.rend(); it++) {
      const auto& num_i  = it->first;
      const auto& freq_i = it->second;

      for(auto jt = it; jt != nums_map.rend(); jt++) {
        const auto& num_j  = jt->first;
        const auto& freq_j = jt->second;

        sum += num_i/num_j*freq_i*freq_j;
        sum = sum%(1000000000 + 7);
      }
    }

    return sum;
  }
};

int main() {
  std::vector<int> nums = {2,5,9};

  const auto result = Solution().sumOfFlooredPairs(nums);

  std::cout << result << std::endl;
}