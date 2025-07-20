#include<iostream>
#include<stack>
#include<string>
#include<vector>

using string = std::string;

class Solution {
public:
  bool isValid(string s) {
    std::stack<char> track;

    if(s.size() < 2) return false;

    for(const auto c : s) {
      if(c == ')' || c == ']' || c == '}') {
        if(track.size() == 0) return false;
        else if(c == ')' && track.top() == '(') track.pop();
        else if(c == '}' && track.top() == '{') track.pop();
        else if(c == ']' && track.top() == '[') track.pop();
        else return false;
      } else {
        track.push(c);
      }
    }

    if(track.size() != 0) return false;

    return true;
  }
};

int main() {
  const string s = "()";

  const auto result = Solution().isValid(s) ? "True" : "False";
  std::cout << result << std::endl;

  return 0;
}