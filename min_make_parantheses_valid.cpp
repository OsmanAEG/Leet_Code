#include<iostream>
#include<stack>
#include<string>

using string = std::string;

class Solution {
public:
  int minAddToMakeValid(string s) {
    std::stack<char> opens;
    int closed = 0;

    for(const auto& c : s) {
      if(c == '(') {
        opens.push(c);
      } else if(opens.size() > 0 && c == ')') {
        opens.pop();
      } else {
        closed += 1;
      }
    }

    return opens.size() + closed;
  }
};

int main() {
  string s = "(((";

  const auto result = Solution().minAddToMakeValid(s);
  std::cout << result << std::endl;

  return 0;
}