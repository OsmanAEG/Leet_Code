#include<string>

using string = std::string;

class Solution {
public:
  bool rotateString(string s, string goal) {
    const int n = s.size();

    for(int i = 0; i < n; ++i) {
      if(s == goal) return true;

      char s_0 = s[0];
      s.erase(0, 1);
      s.push_back(s_0);
    }

    return false;
  }
};