#include<iostream>
#include<vector>

class Solution {
public:
  int removeElement(std::vector<int>& nums, int val) {
    int it = 0;

    while(it < nums.size()) {
      if(nums[it] == val) nums.erase(nums.begin() + it);
      else ++it;
    }

    return nums.size();
  }
};