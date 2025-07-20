#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
  int maxNumberOfBalloons(std::string text) {
    std::unordered_map<char, int> dict;
    std::vector<char> balloon = {'b', 'a', 'l', 'o', 'n'};
    int min = 10000;

    for(auto& c : text) if(c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') dict[c] += 1;

    for(auto& c : balloon) {
      int num = dict[c];
      if(c == 'l' || c == 'o') num /= 2;
      if(num < min) min = num;
    }

    return min;
  }
};

int main() {
  std::string text = "loonbalxballpoon";
  const auto result = Solution().maxNumberOfBalloons(text);
  std::cout << result << std::endl;
}