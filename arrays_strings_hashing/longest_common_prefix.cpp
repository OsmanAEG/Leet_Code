#include<iostream>
#include<vector>
#include<string>

using string = std::string;

class Solution {
public:
  string longestCommonPrefix(std::vector<string>& strs) {
    if(strs.size() < 1) return "";

    string common_prefix = strs[0];

    for(const auto& str : strs) {
      for(int i = 0; i < common_prefix.size(); ++i) {
        if(common_prefix[i] != str[i]) {
          common_prefix.resize(i);
        }
      }
    }

    return common_prefix;
  }
};

int main() {
  std::vector<string> strs = {"flower", "flow", "flight"};

  const auto result = Solution().longestCommonPrefix(strs);
  std::cout << result << std::endl;

  return 0;
}