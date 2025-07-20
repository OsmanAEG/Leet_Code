#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    std::map<int, int> map;

    for(int i = 0; i < nums.size(); ++i) map[nums[i]] += 1;

    int c = 0;

    for(auto it = map.begin(); it != map.end(); ++it) {
      for(int i = 0; i < it->second; ++i) {
        nums[c] = it->first;
        ++c;
      }
    }

    return nums;
  }
};