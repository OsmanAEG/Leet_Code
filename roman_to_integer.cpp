#include<iostream>
#include<string>
#include<unordered_map>

using string = std::string;

class Solution {
public:
  int romanToInt(string s) {
    int num = 0;

    std::unordered_map<char, int> my_map = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                            {'C', 100}, {'D', 500}, {'M', 1000}};

    bool ignore_next = false;
    for(int i = 0; i < s.size(); ++i) {
      const auto& c = s[i];
      const auto& c_next = s[i+1];

      if(!ignore_next) {
        if(c == 'I' && (c_next == 'V' || c_next == 'X')) {
          num += my_map[c_next] - my_map[c];
          ignore_next = true;
        }else if(c == 'X' && (c_next == 'L' || c_next == 'C')) {
          num += my_map[c_next] - my_map[c];
          ignore_next = true;
        }else if(c == 'C' && (c_next == 'D' || c_next == 'M')) {
          num += my_map[c_next] - my_map[c];
          ignore_next = true;
        }else {
          num += my_map[c];
        }
      }else {
        ignore_next = false;
      }
    }

    return num;
  }
};

int main() {
  string s = "MCMXCIV";

  const auto result = Solution().romanToInt(s);
  std::cout << result << std::endl;

  return 0;
}