#include<iostream>
#include<string>

using string = std::string;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = 0;

    for(const auto& c : t) {
      if(s[i] == c) ++i;
    }

    if(i == s.size()) return true;
    else return false;
  }
};

int main() {
  const string s = "abc";
  const string t = "ahbgdc";

  const auto result = Solution().isSubsequence(s, t);
  std::cout << result << std::endl;

  return 0;
}