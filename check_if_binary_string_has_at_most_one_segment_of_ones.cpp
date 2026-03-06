// LeetCode: 1784

#include <string>

class Solution {
public:
  bool checkOnesSegment(std::string s) {
    bool counted_0 = false;

    for(const auto& c : s) {
      if(c == '0') counted_0 = true;
      if(c == '1' && counted_0 == true) return false;
    }

    return true;
  }
};