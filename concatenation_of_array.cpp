#include<iostream>
#include<vector>

class Solution {
public:
  std::vector<int> getConcatenation(std::vector<int>& nums) {
    auto two_nums = nums;
    for(int i = 0; i < nums.size(); ++i) two_nums.push_back(nums[i]);

    return two_nums;
  }
};