// LeetCode: 3005

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxFrequencyElements(std::vector<int>& nums) {
    int max_freq = 0;
    int num_max  = 0;

    std::unordered_map<int, int> map_freq;

    for(const auto& num : nums) {
      map_freq[num] += 1;
      max_freq = std::max(max_freq, map_freq[num]);
    }

    for(const auto& num : nums) {
      if(map_freq[num] == max_freq) ++num_max;;
    }

    return num_max;
  }
};