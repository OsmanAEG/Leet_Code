#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
  long long maxKelements(std::vector<int>& nums, int k) {
    long long score = 0;
    std::map<int, int> elements;

    for(const auto& el : nums) elements[el] += 1;

    while(k > 0) {
      auto max_val = elements.rbegin();
      score += max_val->first;
      elements[(max_val->first + 2) / 3] += 1;

      max_val->second -= 1;

      if(max_val->second == 0) elements.erase(max_val->first);

      k -= 1;
    }

    return score;
  }
};

int main() {
  std::vector<int> nums = {1,10,3,3,3};
  int k = 3;

  const auto result = Solution().maxKelements(nums, k);
  std::cout << result << std::endl;

  return 0;
}