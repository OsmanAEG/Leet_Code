#include <string>

class Solution {
public:
  int strStr(std::string haystack, std::string needle) {
    if(haystack.size() < needle.size()) return -1;

    for(int i = 0; i < haystack.size(); ++i) {
      bool found_needle = true;

      int j = 0;

      while(j < needle.size() && i + j <= haystack.size()) {
        if(needle[j] != haystack[i+j]) found_needle = false;
        ++j;
      }

      if(found_needle) {
        return i;
      }
    }

    return -1;
  }
};