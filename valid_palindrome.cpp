// LeetCode: 125

#include <algorithm>
#include <cctype>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
      return !std::isalnum(c);
    }), s.end());

    std::transform(s.begin(), s.end(), s.begin(), [](char c) {
      return std::tolower(c);
    });

    int low = 0;
    int high = s.size() - 1;

    while(low < high) {
      if(s[low] != s[high]) {
        return false;
      }

      ++low;
      --high;
    }

    return true;
  }
};