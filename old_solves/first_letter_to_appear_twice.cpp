#include<iostream>
#include<string>
#include<unordered_map>

using string = std::string;

class Solution {
public:
  char repeatedCharacter(string s) {
    std::unordered_map<char, int> twice_check;

    for(const auto& c : s) {
      twice_check[c] += 1;

      if(twice_check[c] == 2) return c;
    }

    return 'a';
  }
};

int main() {
  string s = "abccbaacz";

  const auto result = Solution().repeatedCharacter(s);
  std::cout << result << std::endl;

  return 0;
}