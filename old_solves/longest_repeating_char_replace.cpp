#include<string>
#include<map>

using string = std::string;

class Solution {
public:
  int characterReplacement(string s, int k) {
    std::map<char, int> my_map;

    int idx1 = 0;
    int idx2 = 0;

    char c_big = s[idx1];
    my_map[c_big] += 1;

    while(idx2 < s.size()) {
      const auto len = idx2 - idx1 + 1;

      if(len - my_map[c_big] > k) {

      } else {
        
      }
    }
  }
};