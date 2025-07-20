#include<iostream>
#include<string>

using string = std::string;

class Solution {
public:
  long long minimumSteps(string s) {
    long long steps = 0;

    long long zeros      = 0;
    long long group_size = 0;

    int r = 0;

    while(r < s.size()) {
      while(r < s.size() && s[r] == '1') {
        ++group_size;
        ++r;
      }

      while(r < s.size() && s[r] == '0') {
        ++zeros;
        ++r;
      }

      steps += group_size*zeros;
      zeros = 0;
    }

    return steps;
  }
};

int main() {
  string s = "01010001";

  const auto result = Solution().minimumSteps(s);
  std::cout << result << std::endl;

  return 0;
}