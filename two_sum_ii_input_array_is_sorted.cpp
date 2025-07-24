// LeetCode: 167

#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int low = 0;
    int high = numbers.size() - 1;

    while(low < high) {
      const auto sum = numbers[low] + numbers[high];

      if(sum > target) {
        --high;
      } else if(sum < target) {
        ++low;
      } else {
        break;
      }
    }

    return {low + 1, high + 1};
  }
};