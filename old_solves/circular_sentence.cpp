#include<iostream>
#include<string>

using string = std::string;

class Solution {
public:
  bool isCircularSentence(string sentence) {
    const int n = sentence.size();

    if(sentence[0] != sentence[n-1]) return false;

    char c_last = sentence[0];
    char c_next = sentence[2];

    for(int i = 1; i < n-1; ++i) {
      char c_i = sentence[i];
      c_next = sentence[i+1];

      if(c_i == ' ' && c_last != c_next) return false;

      c_last = c_i;
    }

    return true;
  }
};

int main() {
  const string sentence = "leetcode exercises sound delightful";
  const auto result = Solution().isCircularSentence(sentence);
  std::cout << result << std::endl;
  return 0;
}