#include<iostream>
#include<string>

using string = std::string;

class Solution {
public:
  std::string mergeAlternately(string word1, string word2) {
    int w1_idx = 0;
    int w2_idx = 0;

    string merged = "";

    while(w1_idx < word1.size() || w2_idx < word2.size()) {
      if(w1_idx < word1.size()) merged += word1[w1_idx];
      if(w2_idx < word2.size()) merged += word2[w2_idx];

      ++w1_idx;
      ++w2_idx;
    }

    return merged;
  }
};

int main() {
  string word1 = "abc";
  string word2 = "pqr";

  const auto result = Solution().mergeAlternately(word1, word2);
  std::cout << result << std::endl;

  return 0;
}