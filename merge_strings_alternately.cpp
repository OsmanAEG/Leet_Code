// LeetCode: 1768

#include <string>

class Solution {
public:
  std::string mergeAlternately(std::string word1, std::string word2) {
    std::string merged_word = "";

    int i = 0;

    while(i < word1.size() || i < word2.size()) {
      if(i < word1.size()) merged_word += word1[i];
      if(i < word2.size()) merged_word += word2[i];

      ++i;
    }

    return merged_word;
  }
};