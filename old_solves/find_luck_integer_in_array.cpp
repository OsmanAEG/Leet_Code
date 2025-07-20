#include <map>
#include <vector>

class Solution {
public:
  int findLucky(std::vector<int>& arr) {
    std::map<int, int> map;

    for(const auto& num : arr) map[num] += 1;

    for(auto it = map.rbegin(); it != map.rend(); ++it) {
      if(it->first == it->second) return it->first;
    }

    return -1;
  }
};