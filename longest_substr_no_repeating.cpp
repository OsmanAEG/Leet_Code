#include<string>
#include<set>

using string = std::string;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int low = 0;
    int high = 0;

    int max_len = 0;

    std::set<char> unique;

    while(high < s.size()) {
      while(unique.find(s[high]) != unique.end()) {
        unique.erase(s[low]);
        ++low;
      }

      unique.insert(s[high]);

      max_len = std::max(high - low + 1, max_len);

      ++high;
    }

    return max_len;
  }
};