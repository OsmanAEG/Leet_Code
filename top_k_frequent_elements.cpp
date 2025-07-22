// LeetCode: 347

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> nums_map;
    std::vector<std::pair<int, int>> freq;

    std::vector<int> top_freq_nums;

    for(const auto& num : nums) {
      nums_map[num] += 1;
    }

    for(auto it = nums_map.begin(); it != nums_map.end(); ++it) {
      freq.push_back({it->first, it->second});
    }

    std::sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
      return a.second < b.second;
    });

    for(int i = 0; i < k; ++i) {
      top_freq_nums.push_back(freq[freq.size() - i - 1].first);
    }

    return top_freq_nums;
  }
};