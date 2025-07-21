// LeetCode: 49

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> grouped_anagrams;
    std::unordered_map<std::string, std::vector<int>> strs_map;

    for(int i = 0; i < strs.size(); ++i) {
      auto str_idx = strs[i];
      std::sort(str_idx.begin(), str_idx.end());

      strs_map[str_idx].push_back(i);
    }

    for(auto it = strs_map.begin(); it != strs_map.end(); ++it) {
      std::vector<std::string> group;

      for(const auto& str_idx : it->second) {
        group.push_back(strs[str_idx]);
      }

      grouped_anagrams.push_back(group);
    }

    return grouped_anagrams;
  }
};