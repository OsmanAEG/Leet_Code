#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
  int findLHS(std::vector<int>& nums) {
    if(nums.size() <= 1) return 0;

    int length = 0;

    std::map<int, int> map;

    for(const auto& num : nums) map[num] += 1;

    auto l_it = map.begin();
    auto h_it = std::next(map.begin());

    int max_length = 0;

    while(h_it != map.end()) {
      const auto max = h_it->first;
      const auto min = l_it->first;

      if(max - min == 1) {
        max_length = std::max(max_length, l_it->second + h_it->second);
      }

      ++h_it;
      ++l_it;
    }

    return max_length;
  }
};