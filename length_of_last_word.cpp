#include<string>

using string = std::string;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int idx = s.size() - 1;
    int c = 0;

    while(idx >= 0 && s[idx] == ' ') --idx;

    while(idx >= 0 && s[idx] != ' ') {
      ++c;
      --idx;
    }

    return c;
  }
};