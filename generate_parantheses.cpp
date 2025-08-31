// LeetCode: 22

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> valid_ps;

  bool is_valid(std::string ps) {
    std::stack<char> check;

    for(const auto& p : ps) {
      if(p == '(') check.push(p);
      else if(p ==')' && check.empty()) return false;
      else check.pop();
    }

    if(check.empty()) return true;
    else return false;
  }

  void generate_valid_parenthesis(std::string ps, int n) {
    if(ps.size() == 2*n && is_valid(ps)) valid_ps.push_back(ps);

    if(ps.size() < 2*n) {
      auto ps_open  = ps;
      auto ps_close = ps;

      ps_open.push_back('(');
      ps_close.push_back(')');

      generate_valid_parenthesis(ps_open, n);
      generate_valid_parenthesis(ps_close, n);
    }
  }

  std::vector<std::string> generateParenthesis(int n) {
    std::string ps = "(";

    generate_valid_parenthesis(ps, n);

    return valid_ps;
  }
};