// LeetCode: 271

#include <string>
#include <vector>

class Solution {
public:
  std::string encode(std::vector<std::string>& strs) {
    std::string decoded_str;

    for(const auto& str : strs) {
      for(const auto& c : str) {
        decoded_str.push_back(c);
      }

      decoded_str.push_back('\xFF');
    }

    return decoded_str;
  }

  std::vector<std::string> decode(std::string s) {
    std::vector<std::string> encoded_str;

    std::string str;

    for(const auto& c : s) {
      if(c == '\xFF') {
        encoded_str.push_back(str);
        str.clear();
      } else {
        str.push_back(c);
      }
    }

    return encoded_str;
  }
};
