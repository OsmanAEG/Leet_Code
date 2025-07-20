// LeetCode: 242

#include <unordered_map>
#include <string>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if(s.size() != t.size()) return false;

    std::unordered_map<char, int> s_map;
    std::unordered_map<char, int> t_map;

    for(int i = 0; i < s.size(); ++i) {
      s_map[s[i]] += 1;
      t_map[t[i]] += 1;
    }

    for(int i = 0; i < s.size(); ++i) {
      if(s_map[s[i]] != t_map[s[i]]) return false;
    }

    return true;
  }
};