#include<iostream>
#include<string>
#include<stack>

using string = std::string;

class Solution {
public:
  int maximumSwap(int num) {
    string str = std::to_string(num);
    std::stack<std::pair<int, int>> dgts;

    const int n = str.size();
    dgts.push({str[n-1] - '0', n-1});

    for(int i = str.size() - 2; i >= 0; --i) {
      const int dgt = str[i] - '0';
      if(dgt > dgts.top().first) dgts.push({dgt, i});
    }

    for(int i = 0; i < n; ++i) {
      const int dgt = str[i] - '0';

      while(dgts.size() !=0 && dgts.top().second <= i) dgts.pop();
      if(dgts.size() == 0) break;

      if(dgts.top().first > dgt ) {
        std::swap(str[i], str[dgts.top().second]);
        break;
      }
    }

    return std::stoi(str);
  }
};

int main() {
  const int input = 2736;

  const auto result = Solution().maximumSwap(input);
  std::cout << result << std::endl;

  return 0;
}