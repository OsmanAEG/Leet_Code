#include<iostream>
#include<vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int idx_low = 0;
    int idx_high = numbers.size() - 1;

    while(numbers[idx_low] + numbers[idx_high] != target) {
      if(numbers[idx_low] + numbers[idx_high] > target) --idx_high;
      else ++idx_low;
    }

    return {idx_low + 1, idx_high + 1};
  }
};

int main() {
  std::vector<int> numbers = {2,7,11,15};
  const int target = 9;

  const auto result = Solution().twoSum(numbers, target);
  std::cout << "Result: " << result[0] << " and " << result[1] << std::endl;

  return 0;
}