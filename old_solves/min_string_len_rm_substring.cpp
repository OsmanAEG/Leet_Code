#include<iostream>
#include<stack>
#include<string>

using string = std::string;

class Solution {
public:
  int minLength(string s) {
    std::stack<char> letters;

    letters.push(s[0]);

    for(int i = 1; i < s.size(); ++i) {
      string pair = "";

      if(letters.size() > 0){
        pair.push_back(letters.top());
        pair.push_back(s[i]);
      }

      if(pair == "AB" || pair == "CD") letters.pop();
      else letters.push(s[i]);
    }

    return letters.size();
  }
};

int main() {
  string s = "ACBBD";

  const auto result = Solution().minLength(s);
  std::cout << result << std::endl;

  return 0;
}