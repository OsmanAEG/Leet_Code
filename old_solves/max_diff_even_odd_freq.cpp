#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

class Solution {
public:
  int maxDifference(std::string s) {
    std::unordered_map<char, int> map;

    for(const auto& c : s) ++map[c];

    int min_even  = INT_MAX;
    int max_odd  = 0;

    for(auto it = map.begin(); it != map.end(); ++it) {
      const auto freq = it->second;

      if(freq%2 == 0) {
        min_even = std::min(min_even, freq);
      } else {
        max_odd = std::max(max_odd, freq);
      }
    }

    return max_odd - min_even;
  }
};