// LeetCode: 128

#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    std::map<int, int> map;

    for(const auto& num : nums) map[num] += 1;

    int prev = -100;
    int curr_length = 0;
    int max_length  = 0;


    for(auto it = map.begin(); it != map.end(); ++it) {
      if(it->first - prev != 1) {
        max_length = std::max(max_length, curr_length);
        curr_length = 1;
      } else {
        curr_length += 1;
      }

      prev = it->first;
    }

    max_length = std::max(max_length, curr_length);

    return max_length;
  }
};