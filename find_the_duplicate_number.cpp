// LeetCode: 287

#include <unordered_map>
#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> map;
    for(const auto& num : nums) {
      map[num] += 1;

      if(map[num] == 2) return num;
    }

    return 0;
  }
};