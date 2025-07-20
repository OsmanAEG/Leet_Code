#include<iostream>
#include<string>

using string = std::string;

class Solution {
public:
  string compressedString(string word) {
    string comp;

    const int n = word.size();
    int i = 0;

    while(i < n) {
      char c = word[i];
      int it = 1;

      while(i < n -1 && c == word[i+1] && it < 9) {
        ++it;
        ++i;
      }

      ++i;

      comp.push_back('0' + it);
      comp.push_back(c);
    }

    return comp;
  }
};

int main() {
  string word = "abcde";
  const auto result = Solution().compressedString(word);
  std::cout << result << std::endl;
  return 0;
}