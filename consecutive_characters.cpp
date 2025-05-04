#include <algorithm>
#include <string>

class Solution {
public:
  int maxPower(std::string s) {
    if(s.size() == 0) return 0;
    int curr = 1;
    int max = 1;

    for(int i = 1; i < s.size(); ++i) {
      if(s[i] == s[i-1]) {
        ++curr;
        max = std::max(curr, max);
      } else {
        curr = 1;
      }
    }

    return max;
  }
};