// LeetCode: 20

#include <stack>
#include <string>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;

    for(const auto& c : s) {
      if(c == '(' || c == '{' || c == '[') {
        stack.push(c);
      } else {
        if(stack.size() == 0) return false;
        const auto& top = stack.top();

        if(top == '(' && c != ')') return false;
        else if(top == '{' && c != '}') return false;
        else if(top == '[' && c != ']') return false;

        stack.pop();
      }
    }

    if(stack.size() != 0) return false;
    else return true;
  }
};