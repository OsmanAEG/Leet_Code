// LeetCode: 150

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<char> ops;
    std::stack<int> nums;

    for(const auto& c : tokens) {
      if(c == "+" || c == "-" || c == "/" || c == "*") {
        const auto num_1 = nums.top();
        nums.pop();
        const auto num_2 = nums.top();
        nums.pop();

        int res;

        if(c == "+") res = num_2 + num_1;
        else if(c == "-") res = num_2 - num_1;
        else if(c == "/") res = num_2 / num_1;
        else res = num_2 * num_1;

        nums.push(res);
      } else {
        nums.push(std::stoi(c));
      }
    }

    return nums.top();
  }
};