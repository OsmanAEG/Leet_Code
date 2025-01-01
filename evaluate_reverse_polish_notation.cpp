#include<iostream>
#include<stack>
#include<string>
#include<vector>

using string = std::string;

class Solution {
public:
  int evalRPN(std::vector<string>& tokens) {
    std::stack<int> vals;

    for(const auto& token : tokens) {
      if(token == "+" || token == "-" || token == "*" || token == "/") {
        const auto b = vals.top();
        vals.pop();
        const auto a = vals.top();
        vals.pop();

        if(token == "+")      vals.push(a + b);
        else if(token == "-") vals.push(a - b);
        else if(token == "*") vals.push(a * b);
        else if(token == "/") vals.push(a / b);
      } else {
        vals.push(std::stoi(token));
      }
    }

    return vals.top();
  }
};

int main() {
  std::vector<string> input = {"2","1","+","3","*"};

  const auto result = Solution().evalRPN(input);
  std::cout << result << std::endl;

  return 0;
}