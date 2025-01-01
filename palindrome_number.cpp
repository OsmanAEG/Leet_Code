#include <string>

class Solution {
public:
  bool isPalindrome(int x) {
    const auto x_str = std::to_string(x);

    int l = 0;
    int r = x_str.size() - 1;

    while(l < r) {
      if(x_str[l] != x_str[r]) return false;
      ++l;
      --r;
    }

    return true;
  }
};