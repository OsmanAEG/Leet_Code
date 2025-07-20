#include<iostream>
#include<string>
#include<vector>

using string = std::string;

class Solution {
public:
  std::vector<string> summaryRanges(std::vector<int>& nums) {
    nums.push_back(1000);

    int r1 = nums[0];
    int r2 = nums[0];

    std::vector<string> ranges;

    for(int i = 1; i < nums.size(); ++i) {
      const int num = nums[i];
      if(r2 == num - 1) {
        r2 = num;
      } else {
        string range;
        if(r1 == r2) range = std::to_string(r1);
        else range = std::to_string(r1) + "->" + std::to_string(r2);
        r1 = num;
        r2 = num;

        ranges.push_back(range);
      }
    }

    return ranges;
  }
};

int main() {
  std::vector<int> nums = {0,1};

  const auto& result = Solution().summaryRanges(nums);
  for(const auto& range : result) std::cout << range << std::endl;

  return 0;
}